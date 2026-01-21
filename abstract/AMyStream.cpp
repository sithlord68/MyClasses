/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMyStream.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:56:18 by pjolidon          #+#    #+#             */
/*   Updated: 2026/01/21 11:44:39 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AMyStream.hpp"

std::string	AMyStream::_header = "";

void	AMyStream::setHeader( std::string const &header )
{
	_header = header;
}

AMyStream::AMyStream( void ):
	_nbElems( 0 ),
	_ended( false )
{
	// canon default constructor
	this->_iOutput = iOutput;
}

AMyStream::AMyStream(std::ostream* stream, bool autoSp):
	_nbElems( 0 ),
	_ended( false )
{
	setAutoSpace(autoSp);
	if (stream)
		this->_iOutput = stream;
	else
		this->_iOutput = iOutput;
}

AMyStream::AMyStream(bool autoSp):
	_nbElems( 0 ),
	_iOutput( iOutput ),
	_ended( false )
{
	setAutoSpace(autoSp);
}

AMyStream::~AMyStream( void )
{
	// canon destructor
	if (!_nbElems)
		return;
	if (_autoEndl && !this->_ended)
	{
		*this->_iOutput << std::endl;
	}
}

AMyStream::AMyStream( AMyStream const &rhs )
{
	// canon copy constructor
	// not used
	(void)rhs;
}

void	AMyStream::setAutoSpace( bool value )
{
	// set auto space member function
	_autoSpace = value;
}

void	AMyStream::setAutoEndl( bool value )
{
	// set auto endl member function
	_autoEndl = value;
}

void	AMyStream::setOutput( std::ostream *value )
{
	// set output member function
	iOutput = value;
}

AMyStream &	AMyStream::operator<<(std::string value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

AMyStream &AMyStream::operator<<(char* value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

AMyStream &AMyStream::operator<<(char const* value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(int value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(unsigned int value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(char value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(size_t value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(float value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value << "f";
	return *this;
}

AMyStream &	AMyStream::operator<<(double value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(bool value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

// Surcharge pour les manipulateurs de flux (std::endl...)
AMyStream & AMyStream::operator<<(std::ostream& (*manip)(std::ostream&))
{
	*this->_iOutput << manip;
	// Si c'est un endl, on marque comme terminé
	if (manip == static_cast<std::ostream& (*)(std::ostream&)>(std::endl))
		this->_ended = true;
	
	return *this;
}
