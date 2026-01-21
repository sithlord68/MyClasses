/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDebug.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:34:30 by pjolidon          #+#    #+#             */
/*   Updated: 2026/01/21 11:10:22 by pjolidon         ###   ########.fr       */
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

#include "AMyStream.hpp"

class MyDebug: public AMyStream
{
	public:

	private:

		MyDebug( void );								// canon default constructor
		virtual ~MyDebug( void );						// canon destructor
		MyDebug( MyDebug &rhs);							// canon copy constructor
		MyDebug &			operator=( MyDebug &rhs );	// canon = operator

};

#endif
