#!/bin/bash

# ============================================
# Script de sauvegarde complète EliteBook
# Usage: ./backup-to-usb.sh /chemin/du/dossier/backup
# ============================================

# Vérifier qu'un dossier de destination est fourni
if [ -z "$1" ]; then
    echo "Usage: $0 /chemin/vers/dossier/backup"
    echo "Exemple: $0 /media/$USER/USB/backup-ubuntu"
    exit 1
fi

DEST="$1"
DATE=$(date +"%Y%m%d_%H%M%S")
BACKUP_DIR="${DEST}/backup_${DATE}"

# Créer le dossier de backup
mkdir -p "$BACKUP_DIR"
mkdir -p "$BACKUP_DIR/apt"
mkdir -p "$BACKUP_DIR/configs"
mkdir -p "$BACKUP_DIR/dotfiles"
mkdir -p "$BACKUP_DIR/mounts"
mkdir -p "$BACKUP_DIR/scripts"

echo "=== Sauvegarde système vers $BACKUP_DIR ==="

# 1. Liste explicite des paquets (avec version pour compatibilité)
echo "1. Sauvegarde des paquets..."
apt list --installed 2>/dev/null | grep -v "^Listing" > "$BACKUP_DIR/apt/packages-full.txt"
dpkg --get-selections > "$BACKUP_DIR/apt/dpkg-selections.txt"
apt-mark showmanual > "$BACKUP_DIR/apt/manual-packages.txt"

# 2. Dépôts APT et clés
echo "2. Sauvegarde des dépôts..."
cp -r /etc/apt/sources.list* "$BACKUP_DIR/apt/" 2>/dev/null
# Sauvegarde des clés GPG
mkdir -p "$BACKUP_DIR/apt/keys"
sudo cp -r /etc/apt/trusted.gpg.d/* "$BACKUP_DIR/apt/keys/" 2>/dev/null
sudo cp /etc/apt/trusted.gpg "$BACKUP_DIR/apt/keys/" 2>/dev/null

# 3. Points de montage (/etc/fstab et configurations)
echo "3. Sauvegarde des montages..."
cp /etc/fstab "$BACKUP_DIR/mounts/fstab"
# Détail des montages actuels
mount > "$BACKUP_DIR/mounts/mounts-current.txt"
blkid > "$BACKUP_DIR/mounts/blkid.txt"
lsblk -f > "$BACKUP_DIR/mounts/lsblk.txt"

# 4. Dotfiles essentiels
echo "4. Sauvegarde des dotfiles..."
DOTFILES=".bashrc .bash_aliases .profile .bash_logout .inputrc .gitconfig .gitignore .vimrc .config/nvim .local/share/nvim .tmux.conf .zshrc .oh-my-zsh"
for file in $DOTFILES; do
    if [ -e "$HOME/$file" ]; then
        mkdir -p "$BACKUP_DIR/dotfiles/$(dirname $file)"
        cp -r "$HOME/$file" "$BACKUP_DIR/dotfiles/$file"
    fi
done

# 5. Scripts personnels dans ~/bin ou ~/.local/bin
echo "5. Sauvegarde des scripts personnels..."
for bindir in "$HOME/bin" "$HOME/.local/bin"; do
    if [ -d "$bindir" ]; then
        cp -r "$bindir" "$BACKUP_DIR/scripts/"
    fi
done

# 6. Extensions et configs spécifiques (Code, Neovim, Git)
echo "6. Sauvegarde des configurations applicatives..."
# VS Code / Codium
if [ -d "$HOME/.config/Code" ]; then
    cp -r "$HOME/.config/Code" "$BACKUP_DIR/configs/vscode"
fi
if [ -d "$HOME/.config/VSCodium" ]; then
    cp -r "$HOME/.config/VSCodium" "$BACKUP_DIR/configs/vscodium"
fi
# Neovim
if [ -d "$HOME/.config/nvim" ]; then
    cp -r "$HOME/.config/nvim" "$BACKUP_DIR/configs/nvim"
fi
# Git templates/hooks
if [ -d "$HOME/.gitconfig" ]; then
    cp "$HOME/.gitconfig" "$BACKUP_DIR/dotfiles/.gitconfig"
fi

# 7. Liste des services système personnalisés
echo "7. Sauvegarde des services..."
systemctl list-unit-files --state=enabled > "$BACKUP_DIR/services-enabled.txt"

# 8. Informations système pour identification
echo "8. Informations système..."
hostname > "$BACKUP_DIR/system-hostname.txt"
lsb_release -a > "$BACKUP_DIR/system-release.txt" 2>/dev/null
uname -r > "$BACKUP_DIR/system-kernel.txt"

# 9. Création d'un script de restauration automatique dans le backup
cat > "$BACKUP_DIR/restore-system.sh" << 'EOF'
#!/bin/bash
# Script de restauration automatique - À exécuter sur la nouvelle installation
# Usage: ./restore-system.sh

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "=== RESTAURATION DU SYSTÈME ==="
echo "Ce script va restaurer tous vos paquets et configurations."
echo "Il doit être exécuté sur une installation UBUNTU FRAÎCHE."
echo ""
read -p "Continuer ? (o/N) " -n 1 -r
echo ""
if [[ ! $REPLY =~ ^[OoYy]$ ]]; then
    exit 1
fi

# 1. Copier les sources APT
echo "1. Restauration des dépôts..."
sudo cp -r "$SCRIPT_DIR/apt/sources.list"* /etc/apt/ 2>/dev/null
sudo cp -r "$SCRIPT_DIR/apt/keys/"* /etc/apt/trusted.gpg.d/ 2>/dev/null
sudo apt update

# 2. Restauration des paquets
echo "2. Installation des paquets..."
sudo dpkg --set-selections < "$SCRIPT_DIR/apt/dpkg-selections.txt"
sudo apt dselect-upgrade -y

# 3. Restauration des dotfiles
echo "3. Restauration des dotfiles..."
for file in "$SCRIPT_DIR/dotfiles/"*; do
    if [ -f "$file" ] || [ -d "$file" ]; then
        cp -r "$file" "$HOME/$(basename "$file")"
    fi
done

# 4. Restauration des scripts
echo "4. Restauration des scripts..."
if [ -d "$SCRIPT_DIR/scripts/bin" ]; then
    mkdir -p "$HOME/bin"
    cp -r "$SCRIPT_DIR/scripts/bin/"* "$HOME/bin/" 2>/dev/null
fi
if [ -d "$SCRIPT_DIR/scripts/local/bin" ]; then
    mkdir -p "$HOME/.local/bin"
    cp -r "$SCRIPT_DIR/scripts/local/bin/"* "$HOME/.local/bin/" 2>/dev/null
fi

# 5. Restauration des configs applicatives
echo "5. Restauration des configurations..."
if [ -d "$SCRIPT_DIR/configs/nvim" ]; then
    mkdir -p "$HOME/.config"
    cp -r "$SCRIPT_DIR/configs/nvim" "$HOME/.config/"
fi

# 6. Restauration de fstab (attention, demande confirmation)
echo "6. Restauration des montages..."
read -p "Voulez-vous restaurer /etc/fstab ? (o/N) " -n 1 -r
echo ""
if [[ $REPLY =~ ^[OoYy]$ ]]; then
    sudo cp "$SCRIPT_DIR/mounts/fstab" /etc/fstab
    echo "  ⚠️ Vérifiez que les UUIDs dans fstab correspondent à vos disques actuels !"
fi

echo "=== RESTAURATION TERMINÉE ==="
echo "Il est recommandé de redémarrer."
EOF

chmod +x "$BACKUP_DIR/restore-system.sh"

# 10. Fichier manifeste pour savoir ce qu'il y a dans ce backup
cat > "$BACKUP_DIR/MANIFEST.txt" << EOF
Backup créé le: $DATE
Machine: $(hostname)
Utilisateur: $USER
Kernel: $(uname -r)
OS: $(lsb_release -ds 2>/dev/null)

Contenu du backup:
- apt/         : Sources APT, clés, liste des paquets
- configs/     : Configurations (nvim, vscode...)
- dotfiles/    : Fichiers de configuration utilisateur
- mounts/      : fstab, blkid, montages actuels
- scripts/     : Scripts personnels
- services-enabled.txt : Services système activés
EOF

echo ""
echo "=== SAUVEGARDE TERMINÉE ==="
echo "Dossier: $BACKUP_DIR"
echo "Taille: $(du -sh $BACKUP_DIR | cut -f1)"
echo ""
echo "Pour restaurer sur une nouvelle machine:"
echo "1. Copiez ce dossier sur la nouvelle machine"
echo "2. Exécutez: cd $BACKUP_DIR && ./restore-system.sh"
