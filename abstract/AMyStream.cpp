/*   AMyStream.cpp                                      :+:      :+:    :+:   */
/*   Created: 2026/01/21 10:56:18 by pjolidon          #+#    #+#             */

#include "AMyStream.hpp"

std::string	AMyStream::_header = "";

void	AMyStream::setHeader( std::string const &header )
{
	_header = header;
}

AMyStream::AMyStream( void ):
	_nbElems( 0 ),
	_ended( false ),
	_iOutput( &std::cout )
{
}

AMyStream::AMyStream(std::ostream* stream, bool autoSpace):
	_nbElems( 0 ),
	_ended( false ),
	_iOutput(stream)
{
	setAutoSpace(autoSpace);
}

AMyStream::AMyStream(bool autoSpace):
	_nbElems( 0 ),
	_ended( false ),
	_iOutput(iOutput)
{
	setAutoSpace(autoSpace);
}

/*
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
*/

AMyStream::AMyStream( AMyStream const &rhs )
{
	// canon copy constructor
	// not used
	(void)rhs;
}

void	AMyStream::setAutoSpace( bool value )
{
	// set auto space member function
	this->_autoSpace = value;
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
