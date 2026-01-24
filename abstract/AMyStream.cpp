/*   AMyStream.cpp                                      :+:      :+:    :+:   */
/*   Created: 2026/01/21 10:56:18 by pjolidon          #+#    #+#             */

#include "AMyStream.hpp"

std::string	AMyStream::_header = "";
std::ostream*	AMyStream::_outputClass    = &std::cout;
bool			AMyStream::_autoSpaceClass = true;
bool			AMyStream::_autoEndlClass  = true;
char			AMyStream::_separatorClass = ' ';
bool			AMyStream::_defaultSet     = false;

AMyStream::~AMyStream( void )
{
	// canon destructor
}

void	AMyStream::setHeader( std::string const &header )
{
	_header = header;
}

AMyStream::AMyStream( void ):
	_output( _outputClass ),
	_autoEndl( _autoEndlClass ),
	_autoSpace( _autoSpaceClass ),
	_separator( _separatorClass ),
	_nbElems( 0 ),
	_ended( false )
{
}
AMyStream::AMyStream( std::ostream* stream, bool autoSpace, bool autoEndl, char separator ):
	_output( stream ),
	_autoEndl( autoEndl ),
	_autoSpace( autoSpace ),
	_separator( separator ),
	_nbElems( 0 ),
	_ended( false )
{
}

AMyStream::AMyStream(std::ostream* stream, bool autoSpace):
	_output( stream ),
	_autoEndl( _autoEndlClass ),
	_autoSpace( autoSpace ),
	_separator( _separatorClass ),
	_nbElems( 0 ),
	_ended( false )
{
}

AMyStream::AMyStream(bool autoSpace):
	_output( _outputClass ),
	_autoEndl( _autoEndlClass ),
	_autoSpace( autoSpace ),
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
	_autoSpaceClass = value;
}

void	AMyStream::setAutoEndl( bool value )
{
	// set auto endl member function
	_autoEndlClass = value;
}

void	AMyStream::setOutput( std::ostream *value )
{
	// set output member function
	_outputClass = value;
}

void	AMyStream::setSeparator( char const c )
{
	_separatorClass = c;
}

AMyStream &	AMyStream::operator<<(std::string value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_output << " ";
	*this->_output << value;
	return *this;
}

AMyStream &AMyStream::operator<<(char* value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_output << " ";
	*this->_output << value;
	return *this;
}

AMyStream &AMyStream::operator<<(char const* value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_output << " ";
	*this->_output << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(int value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_output << " ";
	*this->_output << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(unsigned int value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_output << " ";
	*this->_output << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(char value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_output << " ";
	*this->_output << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(size_t value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_output << " ";
	*this->_output << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(float value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_output << " ";
	*this->_output << value << "f";
	return *this;
}

AMyStream &	AMyStream::operator<<(double value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_output << " ";
	*this->_output << value;
	return *this;
}

AMyStream &	AMyStream::operator<<(bool value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_output << " ";
	*this->_output << value;
	return *this;
}

// Surcharge pour les manipulateurs de flux (std::endl...)
AMyStream & AMyStream::operator<<(std::ostream& (*manip)(std::ostream&))
{
	*this->_output << manip;
	// Si c'est un endl, on marque comme terminé
	if (manip == static_cast<std::ostream& (*)(std::ostream&)>(std::endl))
		this->_ended = true;
	
	return *this;
}

void	AMyStream::setDefaults( std::ostream* stream, std::string  const &header,
					bool const autoSpace, bool const autoEndl)
{
	if (_defaultSet)
		return;

	setOutput(stream);
	setHeader(header);
	setAutoSpace(autoSpace);
	setAutoEndl(autoEndl);
	_defaultSet = true;
}
