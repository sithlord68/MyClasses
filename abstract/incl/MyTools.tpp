/*   MyTools.cpp                                        :+:      :+:    :+:   */
/*   Created: 2026/01/20 19:23:53 by pjolidon          #+#    #+#             */

/*#include "MyTools.hpp"
*/

#ifndef MYTOOLS_IMPLEMENTATION
# define MYTOOLS_IMPLEMENTATION

char	MyTools::toLower( char c )
{
	if ( c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	return c;
}

void	MyTools::toLower( std::string *str )
{
	size_t	len = (*str).length();

	for (size_t i = 0; i < len; i++)
	{
		if ( (*str)[i] >= 'A' && (*str)[i] <= 'Z')
			(*str)[i] += 'a' - 'A';
	}
}

char	MyTools::toUpper( char c )
{
	if ( c >= 'a' && c <= 'z')
		return c - 'a' + 'A';
	return c;
}

void	MyTools::toUpper( std::string *str )
{
	size_t	len = (*str).length();

	for (size_t i = 0; i < len; i++)
	{
		if ( (*str)[i] >= 'a' && (*str)[i] <= 'z')
			(*str)[i] += 'A' - 'a';
	}
}

bool	MyTools::isEntier( float f )
{
	long	l = static_cast<long>(f);
	if (static_cast<float>(l) == f)
		return true;
	return false;
}

bool	MyTools::isEntier( double d )
{
	long	l = static_cast<long>(d);
	if (static_cast<float>(l) == d)
		return true;
	return false;
}

MyTools::MyTools( void )
{
	// canon defautl constructor not used
}

MyTools::MyTools( MyTools & rhs )
{
	// canon copy constructor not used
	(void)rhs;
}

MyTools::~MyTools( void )
{
	// canon default destructor not used
}

MyTools &MyTools::operator=( MyTools & rhs )
{
	// canon = operator not used
	(void)rhs;
	return *this;
}

#endif
