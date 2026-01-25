/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDebug.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:35:17 by pjolidon          #+#    #+#             */
/*   Updated: 2026/01/25 19:39:35 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#ifndef MYDEBUG_IMPLEMENTATION
# define MYDEBUG_IMPLEMENTATION

std::string	MyDebug::_header = "[debug]";

MyDebug::~MyDebug( void )
{
	// canon destructor
}

MyDebug::MyDebug( void ):
	AMyStream( &std::clog, true)
{
	setDefaults(&std::clog, true, true);
}

MyDebug::MyDebug(bool autoSpace):
	AMyStream( &std::clog, autoSpace)
{
	setDefaults(&std::clog, autoSpace, true);
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

void	MyDebug::setHeader( std::string const &header )
{
	_header = header;
}

void	MyDebug::outputHeader( void )
{
	if ( MYDEBUG && !this->_nbElems && _header.size() )
	{
		*_output << _header;
		this->_nbElems++;
	}
}

#endif
