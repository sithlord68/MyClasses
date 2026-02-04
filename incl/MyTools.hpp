/*   MyTools.hpp                                        :+:      :+:    :+:   */
/*   Created: 2026/01/20 16:58:32 by pjolidon          #+#    #+#             */

#include <string>
#include <iostream>
#include <cstdlib>

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

		static int	myRandom(int min, int max);
};

# include "MyTools.tpp"

#endif
