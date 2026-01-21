/*   MyDebug.cpp                                        :+:      :+:    :+:   */
/*   Created: 2025/11/06 14:35:17 by pjolidon          #+#    #+#             */

#include "MyDebug.hpp"

// Initialisation des attributs statiques
//std::ostream*	_iOutput = &std::clog;	// io clog


MyDebug::~MyDebug( void )
{
	// canon destructor
	if (!MYDEBUG)
		return;
}

MyDebug::MyDebug( void ):
	AMyStream( &std::clog, true)
{
}

MyDebug::MyDebug(bool autoSpace)
{
	this->_autoSpace = autoSpace;
	this->_autoEndl = true;
	this->_nbElems = 0;
	this->_ended = false;
	this->_iOutput = &std::clog;
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
