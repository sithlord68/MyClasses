/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyTools.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:58:32 by pjolidon          #+#    #+#             */
/*   Updated: 2026/01/20 19:24:49 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyDisplay.hpp"
#include "MyDebug.hpp"

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
