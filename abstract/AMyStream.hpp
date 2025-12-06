/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMyStream.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:23:09 by pjolidon          #+#    #+#             */
/*   Updated: 2025/12/06 21:57:31 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>

#ifndef AMyStream_HPP
# define AMyStream_HPP

class AMyStream
{
	public:
		// Constructeurs
		AMyStream();
		AMyStream(std::ostream* stream, bool autoSp);
		explicit AMyStream(bool autoSp);
		virtual ~AMyStream();

		// Configuration statique (comme avant)
		static void setAutoSpace(bool value);
		static void setAutoEndl(bool value);
		static void setOutput(std::ostream* value);

		// Opérateurs de flux
		AMyStream &operator<<(const std::string& value);
		AMyStream &operator<<(const char* value);
		AMyStream &operator<<(int value);
		AMyStream &operator<<(float value);
		AMyStream &operator<<(bool value);
		AMyStream &operator<<(std::ostream& (*manip)(std::ostream&));

	protected:
		// Méthode helper pour factoriser
		template<typename T>
		AMyStream &_output(const T& value, bool checkEnabled = true) {
			(void)checkEnabled; // Paramètre inutilisé dans la base
			if (this->_autoSpace && this->_nbElems++)
				*this->_iOutput << " ";
			*this->_iOutput << value;
			return *this;
		}

		// Membres protégés pour héritage
		int					_nbElems;
		std::ostream*		_iOutput;
		bool				_ended;
		bool				_autoSpace;
		
		// Membres statiques partagés
		static bool			autoEndl;
		static bool			autoSpace;
		static std::ostream* iOutput;

	private:
		// Interdire copie
		AMyStream(const AMyStream&);
		AMyStream& operator=(const AMyStream&);
};


#endif
