/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDisplay.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:35:17 by pjolidon          #+#    #+#             */
/*   Updated: 2026/01/21 10:52:46 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MyDisplay.hpp"

// Initialisation des attributs statiques
std::ostream*	_iOutput = &std::cout;	// io clog
bool 			_autoEndl = true;		// _autoEndl yes
bool			_autoSpace = true;		// _autoSpace yes


MyDisplay::~MyDisplay( void )
{
	// canon destructor
}

MyDisplay &	MyDisplay::operator<<(std::string value)
{
	AMyStream::operator<<(value);
	return *this;
}

MyDisplay &MyDisplay::operator<<(char* value)
{
	AMyStream::operator<<(value);
	return *this;
}

MyDisplay &MyDisplay::operator<<(char const* value)
{
	AMyStream::operator<<(value);
	return *this;
}

MyDisplay &	MyDisplay::operator<<(int value)
{
	AMyStream::operator<<(value);
	return *this;
}

MyDisplay &	MyDisplay::operator<<(unsigned int value)
{
	AMyStream::operator<<(value);
	return *this;
}

MyDisplay &	MyDisplay::operator<<(char value)
{
	AMyStream::operator<<(value);
	return *this;
}

MyDisplay &	MyDisplay::operator<<(size_t value)
{
	AMyStream::operator<<(value);
	return *this;
}

MyDisplay &	MyDisplay::operator<<(float value)
{
	AMyStream::operator<<(value);
	return *this;
}

MyDisplay &	MyDisplay::operator<<(double value)
{
	AMyStream::operator<<(value);
	return *this;
}

MyDisplay &	MyDisplay::operator<<(bool value)
{
	AMyStream::operator<<(value);
	return *this;
}