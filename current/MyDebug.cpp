/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDebug.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:35:17 by pjolidon          #+#    #+#             */
/*   Updated: 2026/01/21 10:51:57 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MyDebug.hpp"

// Initialisation des attributs statiques
std::ostream*	MyDebug::iOutput = &std::clog;	// io clog
bool 			MyDebug::_autoEndl = true;		// _autoEndl yes
bool			MyDebug::_autoSpace = true;		// _autoSpace yes

/*
template<typename T>
MyDebug classDebug(const T& obj) {
    return MyDebug() << "[" << typeid(T).name() << "] ";
}
*/

MyDebug::MyDebug( void ):
	_nbElems( 0 ),
	_ended( false )
{
	// canon default constructor
	this->_iOutput = iOutput;
}

MyDebug::MyDebug(std::ostream* stream, bool autoSp):
	_nbElems( 0 ),
	_ended( false )
{
	setAutoSpace(autoSp);
	if (stream)
		this->_iOutput = stream;
	else
		this->_iOutput = iOutput;
}

MyDebug::MyDebug(bool autoSp):
	_nbElems( 0 ),
	_iOutput( iOutput ),
	_ended( false )
{
	setAutoSpace(autoSp);
}

MyDebug::~MyDebug( void )
{
	// canon destructor
	if (!MYDEBUG)
		return;
	if (_autoEndl && !this->_ended)
	{
		*this->_iOutput << std::endl;
	}
}

MyDebug::MyDebug( MyDebug &rhs)
{
	// canon copy constructor
	// not used
	(void)rhs;
}

MyDebug &	MyDebug::operator=( MyDebug &rhs )
{
	// canon = operator
	// not used
	(void)rhs;
	return rhs;
}

void	MyDebug::setAutoSpace( bool value )
{
	// set auto space member function
	_autoSpace = value;
}

void	MyDebug::setAutoEndl( bool value )
{
	// set auto endl member function
	_autoEndl = value;
}

void	MyDebug::setOutput( std::ostream *value )
{
	// set output member function
	iOutput = value;
}

MyDebug &	MyDebug::operator<<(std::string value)
{
	if (!MYDEBUG)
		return *this;
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDebug &MyDebug::operator<<(char* value)
{
	if (!MYDEBUG)
		return *this;
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDebug &MyDebug::operator<<(char const* value)
{
	if (!MYDEBUG)
		return *this;
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDebug &	MyDebug::operator<<(int value)
{
	if (!MYDEBUG)
		return *this;
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDebug &	MyDebug::operator<<(unsigned int value)
{
	if (!MYDEBUG)
		return *this;
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDebug &	MyDebug::operator<<(char value)
{
	if (!MYDEBUG)
		return *this;
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDebug &	MyDebug::operator<<(size_t value)
{
	if (!MYDEBUG)
		return *this;
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDebug &	MyDebug::operator<<(float value)
{
	if (!MYDEBUG)
		return *this;
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value << "f";
	return *this;
}

MyDebug &	MyDebug::operator<<(double value)
{
	if (!MYDEBUG)
		return *this;
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

MyDebug &	MyDebug::operator<<(bool value)
{
	if (!MYDEBUG)
		return *this;
	if (_autoSpace && this->_nbElems++)
		*this->_iOutput << " ";
	*this->_iOutput << value;
	return *this;
}

// Surcharge pour les manipulateurs de flux (std::endl...)
MyDebug & MyDebug::operator<<(std::ostream& (*manip)(std::ostream&))
{
	if (!MYDEBUG)
		return *this;
	
	*this->_iOutput << manip;
	
	// Si c'est un endl, on marque comme terminé
	if (manip == static_cast<std::ostream& (*)(std::ostream&)>(std::endl))
		this->_ended = true;
	
	return *this;
}
