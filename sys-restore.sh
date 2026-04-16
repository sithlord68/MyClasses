#!/bin/bash

# ============================================
# Script de restauration complète
# À exécuter sur l'installation UBUNTU FRAÎCHE
# Usage: ./restore-from-usb.sh /chemin/du/dossier/backup
# ============================================

# Couleurs pour l'affichage
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Vérifier qu'un dossier de backup est fourni
if [ -z "$1" ]; then
    echo -e "${RED}Usage: $0 /chemin/vers/dossier/backup${NC}"
    echo "Exemple: $0 /media/$USER/USB/backup_20250416_120000"
    exit 1
fi

BACKUP_DIR="$1"

# Vérifier que le dossier contient un backup valide
if [ ! -f "$BACKUP_DIR/apt/dpkg-selections.txt" ]; then
    echo -e "${RED}Erreur: $BACKUP_DIR ne contient pas un backup valide${NC}"
    echo "Assurez-vous de pointer vers le dossier backup_YYYYMMDD_HHMMSS"
    exit 1
fi

echo -e "${GREEN}=== RESTAURATION DU SYSTÈME ===${NC}"
echo "Backup source: $BACKUP_DIR"
echo "Date du backup: $(cat $BACKUP_DIR/MANIFEST.txt | grep "créé le" | cut -d: -f2)"
echo "Machine source: $(cat $BACKUP_DIR/MANIFEST.txt | grep "Machine" | cut -d: -f2)"
echo ""
echo -e "${YELLOW}⚠️  Ce script va modifier votre système en profondeur.${NC}"
echo "Il est destiné à être exécuté sur une installation UBUNTU FRAÎCHE."
echo ""
read -p "Continuer ? (o/N) " -n 1 -r
echo ""
if [[ ! $REPLY =~ ^[OoYy]$ ]]; then
    echo "Annulé."
    exit 0
fi

# 1. Vérifier la connexion Internet
echo -e "\n${GREEN}[1/6] Vérification de la connexion Internet...${NC}"
if ! ping -c 1 google.com > /dev/null 2>&1; then
    echo -e "${RED}⚠️  Pas de connexion Internet détectée${NC}"
    echo "La restauration des paquets nécessite Internet."
    read -p "Continuer quand même ? (o/N) " -n 1 -r
    echo ""
    if [[ ! $REPLY =~ ^[OoYy]$ ]]; then
        exit 1
    fi
else
    echo -e "${GREEN}✓ Connecté${NC}"
fi

# 2. Restaurer les dépôts APT
echo -e "\n${GREEN}[2/6] Restauration des dépôts APT...${NC}"
if [ -d "$BACKUP_DIR/apt/keys" ] && [ "$(ls -A $BACKUP_DIR/apt/keys)" ]; then
    sudo cp -r "$BACKUP_DIR/apt/keys/"* /etc/apt/trusted.gpg.d/ 2>/dev/null
    echo "  ✓ Clés GPG restaurées"
fi

if [ -f "$BACKUP_DIR/apt/sources.list" ]; then
    sudo cp "$BACKUP_DIR/apt/sources.list" /etc/apt/sources.list
    echo "  ✓ sources.list restauré"
fi

if [ -d "$BACKUP_DIR/apt/sources.list.d" ]; then
    sudo cp -r "$BACKUP_DIR/apt/sources.list.d/"* /etc/apt/sources.list.d/ 2>/dev/null
    echo "  ✓ sources.list.d restauré"
fi

echo "  Mise à jour des dépôts..."
sudo apt update

# 3. Restaurer les paquets
echo -e "\n${GREEN}[3/6] Restauration des paquets...${NC}"
echo "  (cela peut prendre du temps...)"
sudo dpkg --set-selections < "$BACKUP_DIR/apt/dpkg-selections.txt"
sudo apt dselect-upgrade -y

if [ $? -eq 0 ]; then
    echo -e "${GREEN}  ✓ Paquets installés avec succès${NC}"
else
    echo -e "${YELLOW}  ⚠️ Certains paquets n'ont pas pu être installés${NC}"
    echo "  (paquets obsolètes ou dépôts manquants)"
fi

# 4. Restaurer les dotfiles
echo -e "\n${GREEN}[4/6] Restauration des dotfiles...${NC}"
if [ -d "$BACKUP_DIR/dotfiles" ]; then
    for item in "$BACKUP_DIR/dotfiles/"*; do
        name=$(basename "$item")
        if [ -e "$HOME/$name" ]; then
            echo "  ⚠️ $name existe déjà, sauvegarde vers ${name}.backup"
            mv "$HOME/$name" "$HOME/${name}.backup" 2>/dev/null
        fi
        cp -r "$item" "$HOME/" 2>/dev/null
        echo "  ✓ $name restauré"
    done
    echo -e "${GREEN}  ✓ Dotfiles restaurés${NC}"
fi

# 5. Restaurer les scripts personnels
echo -e "\n${GREEN}[5/6] Restauration des scripts personnels...${NC}"
if [ -d "$BACKUP_DIR/scripts/bin" ]; then
    mkdir -p "$HOME/bin"
    cp -r "$BACKUP_DIR/scripts/bin/"* "$HOME/bin/" 2>/dev/null
    echo "  ✓ Scripts restaurés dans ~/bin"
fi

if [ -d "$BACKUP_DIR/scripts/local/bin" ]; then
    mkdir -p "$HOME/.local/bin"
    cp -r "$BACKUP_DIR/scripts/local/bin/"* "$HOME/.local/bin/" 2>/dev/null
    echo "  ✓ Scripts restaurés dans ~/.local/bin"
fi

# 6. Restaurer les configurations applicatives
echo -e "\n${GREEN}[6/6] Restauration des configurations applicatives...${NC}"
if [ -d "$BACKUP_DIR/configs/nvim" ]; then
    mkdir -p "$HOME/.config"
    cp -r "$BACKUP_DIR/configs/nvim" "$HOME/.config/"
    echo "  ✓ Neovim restauré"
fi

if [ -d "$BACKUP_DIR/configs/vscode" ]; then
    mkdir -p "$HOME/.config"
    cp -r "$BACKUP_DIR/configs/vscode" "$HOME/.config/Code"
    echo "  ✓ VS Code restauré"
fi

# 7. Restauration de fstab (optionnelle)
echo -e "\n${YELLOW}[7/7] Restauration des montages (optionnelle)${NC}"
if [ -f "$BACKUP_DIR/mounts/fstab" ]; then
    read -p "Restaurer /etc/fstab ? (o/N) " -n 1 -r
    echo ""
    if [[ $REPLY =~ ^[OoYy]$ ]]; then
        # Sauvegarde de l'ancien fstab
        sudo cp /etc/fstab /etc/fstab.original.backup
        sudo cp "$BACKUP_DIR/mounts/fstab" /etc/fstab
        echo -e "${GREEN}  ✓ /etc/fstab restauré${NC}"
        echo -e "${YELLOW}  ⚠️ VÉRIFIEZ que les UUIDs correspondent à vos disques actuels !${NC}"
        echo "  Pour vérifier: lsblk -f"
        echo "  L'ancien fstab a été sauvegardé dans /etc/fstab.original.backup"
    fi
fi

# 8. Nettoyage final
echo -e "\n${GREEN}=== RESTAURATION TERMINÉE ===${NC}"
echo ""
echo "Actions recommandées:"
echo "  1. Redémarrez votre session ou votre machine"
echo "  2. Vérifiez vos montages avec 'mount | grep /dev'"
echo "  3. Vérifiez vos scripts: ls -la ~/bin ~/.local/bin"
echo "  4. Vérifiez vos dotfiles: ls -la ~/ | grep '^\.'"
echo ""
echo "En cas de problème avec fstab:"
echo "  sudo nano /etc/fstab  # pour corriger"
echo "  ou restaurez la sauvegarde: sudo cp /etc/fstab.original.backup /etc/fstab"
