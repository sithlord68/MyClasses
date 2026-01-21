/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDebug.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:35:17 by pjolidon          #+#    #+#             */
/*   Updated: 2026/01/21 11:21:27 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MyDebug.hpp"

// Initialisation des attributs statiques
std::ostream*	_iOutput = &std::clog;	// io clog
bool 			_autoEndl = true;		// _autoEndl yes
bool			_autoSpace = true;		// _autoSpace yes

MyDebug::~MyDebug( void )
{
	// canon destructor
	if (!MYDEBUG)
		return;
}

MyDebug &	MyDebug::operator<<(std::string value)
{
	if (!MYDEBUG)
		return *this;
	AMyStream::operator<<(value);
	return *this;
}

MyDebug &MyDebug::operator<<(char* value)
{
	if (!MYDEBUG)
		return *this;
	AMyStream::operator<<(value);
	return *this;
}

MyDebug &MyDebug::operator<<(char const* value)
{
	if (!MYDEBUG)
		return *this;
	AMyStream::operator<<(value);
	return *this;
}

MyDebug &	MyDebug::operator<<(int value)
{
	if (!MYDEBUG)
		return *this;
	AMyStream::operator<<(value);
	return *this;
}

MyDebug &	MyDebug::operator<<(unsigned int value)
{
	if (!MYDEBUG)
		return *this;
	AMyStream::operator<<(value);
	return *this;
}

MyDebug &	MyDebug::operator<<(char value)
{
	if (!MYDEBUG)
		return *this;
	AMyStream::operator<<(value);
	return *this;
}

MyDebug &	MyDebug::operator<<(size_t value)
{
	if (!MYDEBUG)
		return *this;
	AMyStream::operator<<(value);
	return *this;
}

MyDebug &	MyDebug::operator<<(float value)
{
	if (!MYDEBUG)
		return *this;
	AMyStream::operator<<(value);
	return *this;
}

MyDebug &	MyDebug::operator<<(double value)
{
	if (!MYDEBUG)
		return *this;
	AMyStream::operator<<(value);
	return *this;
}

MyDebug &	MyDebug::operator<<(bool value)
{
	if (!MYDEBUG)
		return *this;
	AMyStream::operator<<(value);
	return *this;
}
