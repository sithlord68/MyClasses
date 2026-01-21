/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:06:58 by pjolidon          #+#    #+#             */
/*   Updated: 2025/12/19 15:57:35 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>
#include <exception>

#include "MyDebug.hpp"
#include "MyDisplay.hpp"

#ifndef INTERN_HPP
# define INTERN_HPP

class Intern
{
    public:
        Intern( void );                 // canon
        Intern( Intern const &rhs );    // canon
        ~Intern();                      // canon

        Intern &operator=( Intern const &rhs );  // canon
        void    makeForm( std::string formname, std::string target );

    private:

        static const std::string	className;

};

std::ostream & operator<<(std::ostream & io, const Intern &rhs);

#endif
