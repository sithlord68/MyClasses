/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDisplay.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:35:17 by pjolidon          #+#    #+#             */
/*   Updated: 2026/01/25 19:39:05 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MYDISPLAY_IMPLEMENTATION
# define MYDISPLAY_IMPLEMENTATION

std::string	MyDisplay::_header = "";

MyDisplay::~MyDisplay( void )
{
	// canon destructor
}

MyDisplay::MyDisplay( void )
{
	setDefaults(&std::cout, true, true);
}

MyDisplay::MyDisplay(bool autoSpace)
{
	setDefaults(&std::cout, autoSpace, true);
}

MyDisplay::MyDisplay(std::ostream* stream, bool autoSpace)
{
	setDefaults(stream, autoSpace, true);
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

void	MyDisplay::setHeader( std::string const &header )
{
	_header = header;
}

void	MyDisplay::outputHeader( void )
{
	if ( !this->_nbElems && _header.size() )
	{
		*_output << _header;
		this->_nbElems++;
	}
}

#endif
