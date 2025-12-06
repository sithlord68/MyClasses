/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDebug.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:34:30 by pjolidon          #+#    #+#             */
/*   Updated: 2025/12/06 22:00:20 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AMyStream.hpp"

#include <string>
#include <iostream>
#include <typeinfo>

#ifndef MYDEBUG_HPP
# define MYDEBUG_HPP

# ifndef MYDEBUG
#  define MYDEBUG 0
# endif

class MyDebug : public AMyStream
{
	public:
		// Constructeurs
		MyDebug();
		MyDebug(std::ostream* stream, bool autoSp);
		explicit MyDebug(bool autoSp);
		~MyDebug();

		// Redéfinition des opérateurs avec vérification MYDEBUG
		MyDebug &operator<<(const std::string& value);
		MyDebug &operator<<(const char* value);
		MyDebug &operator<<(int value);
		MyDebug &operator<<(float value);
		MyDebug &operator<<(bool value);
		MyDebug &operator<<(std::ostream& (*manip)(std::ostream&));

		// Méthode spécifique pour contexte
		MyDebug& withContext(const std::string& context);
		
		// Version template pour faciliter l'utilisation
		template<typename T>
		static MyDebug classDebug(const T& obj, const std::string& readableName) {
			MyDebug debug;
			return debug.withContext(readableName);
		}

		// Version avec typeid
		template<typename T>
		static MyDebug classDebug(const T& obj) {
			MyDebug debug;
			return debug.withContext(typeid(T).name());
		}

	private:
		MyDebug(const MyDebug&);
		MyDebug& operator=(const MyDebug&);
};

#endif
