/*   MyTools.hpp                                        :+:      :+:    :+:   */
/*   Created: 2026/01/20 16:58:32 by pjolidon          #+#    #+#             */

//#include "MyDisplay.hpp"
#include "MyDebug.hpp"
#include <string>
#include <iostream>
#include <cstdint>		// pour int64_t a la place de long long

#ifndef MYTOOLS_HPP
# define MYTOOLS_HPP

class MyTools
{
	private:

		MyTools( void );
		~MyTools( void );
		MyTools( MyTools & rhs );
		MyTools &operator=( MyTools & rhs );

	public:
	
		static char	toLower( char c );
		static void	toLower( std::string *str );
		static char	toUpper( char c );
		static void	toUpper( std::string *str );
		static bool	isEntier( float f );
		static bool	isEntier( double d );
		
};

#endif
