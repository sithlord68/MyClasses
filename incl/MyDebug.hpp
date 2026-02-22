/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDebug.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:34:30 by pjolidon          #+#    #+#             */
/*   Updated: 2026/02/21 22:15:23 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>
#include <typeinfo>

#ifndef MYDEBUG_HPP
# define MYDEBUG_HPP

# ifndef MYDEBUG
#  define MYDEBUG 0
# endif

class MyDebug
{
	public:

		MyDebug( void );									// canon default constructor
		~MyDebug( void );									// canon destructor

		MyDebug( MyDebug &rhs);								// canon copy constructor
		MyDebug &			operator=( MyDebug &rhs );	// canon = operator

		void				setAutoSpace( bool value );
		void				setAutoEndl( bool value );
		void				setOutput( std::ostream *value );

		MyDebug( std::ostream &stream, bool autoSpace );
		MyDebug( std::ostream &stream );
		MyDebug( bool autoSpace );

		MyDebug &operator<<(std::string value);
		MyDebug &operator<<(int value);
		MyDebug &operator<<(float value);
		MyDebug &operator<<(bool value);
		MyDebug &operator<<(std::ostream value);
		MyDebug &operator<<(const char* value);
		MyDebug &operator<<(unsigned int value);
		MyDebug &operator<<(long value);
		MyDebug &operator<<(double value);

		MyDebug & operator<<(std::ostream& (*manip)(std::ostream&));   // pour operteurs de flux (fonction) tels que std::endl

	private:

		int					_nbElems;
		std::ostream		*_iOutput;
		bool				_ended;
		bool				_autoSpace;
		static bool			autoEndl;
		static bool			autoSpace;
		static std::ostream	*iOutput;

};

#endif

/*
		MyDebug& withContext(const std::string& context) {
			if (_nbElems == 0) {
				*_iOutput << "[" << context << "] ";
				_nbElems++;
			}
			return *this;
		}
		// Template comme fonction membre
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
*/