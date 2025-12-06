/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDisplay.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:35:17 by pjolidon          #+#    #+#             */
/*   Updated: 2025/12/06 11:51:03 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MyDisplay.hpp"

// Initialisation des attributs statiques
std::ostream*	MyDisplay::iOutput = &std::cout;	// io clog
bool 			MyDisplay::autoEndl = true;		// autoEndl yes
bool			MyDisplay::autoSpace = true;		// autoSpace yes

MyDisplay::MyDisplay( void ):
	_nbElems( 0 ),
	_ended( false ),
	_autoSpace( true )
{
	// canon default constructor
	this->_iOutput = iOutput;
}

MyDisplay::MyDisplay(std::ostream* stream, bool autoSp):
	_nbElems( 0 ),
	_ended( false ),
	_autoSpace( autoSp )
{
	if (stream)
		this->_iOutput = stream;
	else
		this->_iOutput = iOutput;
}

MyDisplay::~MyDisplay( void )
{
	// canon destructor
	if (autoEndl && !this->_ended)
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
	autoSpace = value;
}

void	MyDisplay::setAutoEndl( bool value )
{
	// set auto endl member function
	autoEndl = value;
}

void	MyDisplay::setOutput( std::ostream *value )
{
	// set output member function
	iOutput = value;
}

MyDisplay &	MyDisplay::operator<<(std::string value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDisplay &MyDisplay::operator<<(const char* value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDisplay &	MyDisplay::operator<<(int value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDisplay &	MyDisplay::operator<<(float value)
{
	if (this->_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDisplay &	MyDisplay::operator<<(bool value)
{
	if (this->_autoSpace && this->_nbElems++)
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
