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
std::ostream*	MyDisplay::iOutput = &std::cout;	// io clog
bool 			MyDisplay::_autoEndl = true;		// autoEndl yes
bool			MyDisplay::_autoSpace = true;		// autoSpace yes

MyDisplay::MyDisplay( void ):
	_nbElems( 0 ),
	_ended( false )
{
	// canon default constructor
	this->_iOutput = iOutput;
}

MyDisplay::MyDisplay(std::ostream* stream, bool autoSp):
	_nbElems( 0 ),
	_ended( false )
{
	setAutoSpace(autoSp);
	if (stream)
		this->_iOutput = stream;
	else
		this->_iOutput = iOutput;
}

MyDisplay::~MyDisplay( void )
{
	// canon destructor
	if (_autoEndl && !this->_ended)
	{
		*this->_iOutput << std::endl;
	}
}

MyDisplay::MyDisplay( MyDisplay &rhs)
{
	// canon copy constructor
	// not used
	(void)rhs;
}

MyDisplay &	MyDisplay::operator=( MyDisplay &rhs )
{
	// canon = operator
	// not used
	(void)rhs;
	return rhs;
}

void	MyDisplay::setAutoSpace( bool value )
{
	// set auto space member function
	_autoSpace = value;
}

void	MyDisplay::setAutoEndl( bool value )
{
	// set auto endl member function
	_autoEndl = value;
}

void	MyDisplay::setOutput( std::ostream *value )
{
	// set output member function
	iOutput = value;
}

MyDisplay &	MyDisplay::operator<<(std::string value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDisplay &MyDisplay::operator<<(const char* value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDisplay &	MyDisplay::operator<<(int value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDisplay &	MyDisplay::operator<<(unsigned int value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDisplay &	MyDisplay::operator<<(double value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDisplay &	MyDisplay::operator<<(float value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value << "f";
	return *this;
}

MyDisplay &	MyDisplay::operator<<(bool value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

// Surcharge pour les manipulateurs de flux (std::endl...)
MyDisplay & MyDisplay::operator<<(std::ostream& (*manip)(std::ostream&))
{
	*this->_iOutput << manip;
	
	// Si c'est un endl, on marque comme terminé
	if (manip == static_cast<std::ostream& (*)(std::ostream&)>(std::endl))
		this->_ended = true;
	
	return *this;
}

MyDisplay &	MyDisplay::operator<<(size_t value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDisplay &	MyDisplay::operator<<(char value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDisplay &MyDisplay::operator<<(char* value)
{
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}
