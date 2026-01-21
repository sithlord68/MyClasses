/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:06:54 by pjolidon          #+#    #+#             */
/*   Updated: 2025/12/19 16:46:50 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"

static const std::string	className = "[Intern]";

Intern::Intern( void )
{
	MyDebug() << className << "Canon default constructor";
}

Intern::Intern( Intern const &rhs )
{
	MyDebug() << className << "Canon by copy constructor";
}

Intern::~Intern( void )
{
	MyDebug() << className << "canon destructor";
}

Intern &Intern::operator=( Intern const &rhs )
{
	MyDebug() << className << "= canon operator";
}

std::ostream & operator<<(std::ostream & io, const Intern &rhs)
{
//	io << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return io;
}

void    Intern::makeForm( std::string formname, std::string target )
{
   
}
