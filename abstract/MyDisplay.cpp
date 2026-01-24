/*   MyDisplay.cpp                                      :+:      :+:    :+:   */
/*   Created: 2025/11/06 14:35:17 by pjolidon          #+#    #+#             */

#include "MyDisplay.hpp"

// Initialisation des attributs statiques
// std::ostream*	_iOutput = &std::cout;	// io clog

MyDisplay::~MyDisplay( void )
{
	// canon destructor
}

MyDisplay::MyDisplay( void )
{
	setDefaults(&std::cout, "", true, true);
}

MyDisplay::MyDisplay(bool autoSpace)
{
	setDefaults(&std::cout, "", autoSpace, true);
}

MyDisplay::MyDisplay(std::ostream* stream, bool autoSpace)
{
	setDefaults(stream, "", autoSpace, true);
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
