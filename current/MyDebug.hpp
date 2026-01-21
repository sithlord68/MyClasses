/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDebug.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:34:30 by pjolidon          #+#    #+#             */
/*   Updated: 2026/01/21 10:52:00 by pjolidon         ###   ########.fr       */
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

		static void			setAutoSpace( bool value );
		static void			setAutoEndl( bool value );
		static void			setOutput( std::ostream *value );

		MyDebug( std::ostream* stream, bool autoSpace );
		MyDebug( bool autoSpace );

		MyDebug &operator<<(std::string value);
		MyDebug &operator<<(int value);
		MyDebug &operator<<(unsigned int value);
		MyDebug &operator<<(size_t value);
		MyDebug &operator<<(float value);
		MyDebug &operator<<(double value);
		MyDebug &operator<<(bool value);
		MyDebug &operator<<(char* value);
		MyDebug &operator<<(char const *value);
		MyDebug &operator<<(char value);

		MyDebug & operator<<(std::ostream& (*manip)(std::ostream&));   // pour operteurs de flux (fonction) tels que std::endl

	private:

		int					_nbElems;
		std::ostream		*_iOutput;
		bool				_ended;
		static bool			_autoEndl;
		static bool			_autoSpace;
		static std::ostream	*iOutput;

};

#endif
