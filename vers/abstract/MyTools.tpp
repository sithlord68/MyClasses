/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyTools.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:23:53 by pjolidon          #+#    #+#             */
/*   Updated: 2026/02/05 22:25:31 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYTOOLS_IMPLEMENTATION
# define MYTOOLS_IMPLEMENTATION

inline char	MyTools::toLower( char c )
{
	if ( c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	return c;
}

inline void	MyTools::toLower( std::string *str )
{
	size_t	len = (*str).length();

	for (size_t i = 0; i < len; i++)
	{
		if ( (*str)[i] >= 'A' && (*str)[i] <= 'Z')
			(*str)[i] += 'a' - 'A';
	}
}

inline char	MyTools::toUpper( char c )
{
	if ( c >= 'a' && c <= 'z')
		return c - 'a' + 'A';
	return c;
}

inline void	MyTools::toUpper( std::string *str )
{
	size_t	len = (*str).length();

	for (size_t i = 0; i < len; i++)
	{
		if ( (*str)[i] >= 'a' && (*str)[i] <= 'z')
			(*str)[i] += 'A' - 'a';
	}
}

inline bool	MyTools::isEntier( float f )
{
	long	l = static_cast<long>(f);
	if (static_cast<float>(l) == f)
		return true;
	return false;
}

inline bool	MyTools::isEntier( double d )
{
	long	l = static_cast<long>(d);
	if (static_cast<float>(l) == d)
		return true;
	return false;
}

inline MyTools::MyTools( void )
{
	// canon defautl constructor not used
}

inline MyTools::MyTools( MyTools & rhs )
{
	// canon copy constructor not used
	(void)rhs;
}

inline MyTools::~MyTools( void )
{
	// canon default destructor not used
}

inline MyTools &MyTools::operator=( MyTools & rhs )
{
	// canon = operator not used
	(void)rhs;
	return *this;
}

inline int	MyTools::myRandom(int min, int max)
{
	return std::rand() % (max - min + 1) + min;
}

#endif
