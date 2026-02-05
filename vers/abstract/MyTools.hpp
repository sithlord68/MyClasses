/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyTools.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:58:32 by pjolidon          #+#    #+#             */
/*   Updated: 2026/02/05 22:25:42 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>

#ifndef RESET
# define RESET   "\033[0m"
#endif
#ifndef RED
# define RED	 	"\033[31m"
#endif
#ifndef GREEN
# define GREEN   "\033[32m"
#endif
#ifndef YELLOW
# define YELLOW  "\033[33m"
#endif
#ifndef BLUE
# define BLUE	"\033[34m"
#endif
#ifndef MAGENTA
# define MAGENTA "\033[35m"
#endif
#ifndef CYAN
# define CYAN	"\033[36m"
#endif

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
