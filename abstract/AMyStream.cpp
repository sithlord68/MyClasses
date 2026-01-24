/*   AMyStream.cpp                                      :+:      :+:    :+:   */
/*   Created: 2026/01/21 10:56:18 by pjolidon          #+#    #+#             */

#include "AMyStream.hpp"

std::string	AMyStream::_header = "";

void	AMyStream::setHeader( std::string const &header )
{
	_header = header;
}
		std::ostream		*_iOutput;
		bool				_autoEndl;
		bool				_autoSpace;
		char				_separator;
		int					_nbElems;
		bool				_ended;

AMyStream::AMyStream( void ):
	_iOutput( _iOutputClass ),
	_autoEndl( _autoEndlClass ),
	_autoSpace( _autoSpaceClass ),
	_separator( _separatorClass ),
	_nbElems( 0 ),
	_ended( false )
{
}

AMyStream::AMyStream(std::ostream* stream, bool autoSpace):
	_iOutput( stream ),
	_autoEndl( _autoEndlClass ),
	_autoSpace( _autoSpace ),
	_separator( _separatorClass ),
	_nbElems( 0 ),
	_ended( false )
{
}

AMyStream::AMyStream(bool autoSpace):
	_iOutput( _iOutputClass ),
	_autoEndl( _autoEndlClass ),
	_autoSpace( _autoSpace ),
	_separator( _separatorClass ),
	_nbElems( 0 ),
	_ended( false )
{
	setAutoSpace(autoSpace);
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
	this->_autoSpaceClass = value;
}

void	AMyStream::setAutoEndl( bool value )
{
	// set auto endl member function
	_autoEndlClass = value;
}

void	AMyStream::setOutput( std::ostream *value )
{
	// set output member function
	_iOutputClass = value;
}

void	AMyStream::setSeparator( char const c )
{
	_separatorClass = c;
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
