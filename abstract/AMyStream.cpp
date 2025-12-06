/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMyStream.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:36:36 by pjolidon          #+#    #+#             */
/*   Updated: 2025/12/06 21:58:31 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AMyStream.hpp"


std::ostream*	AMyStream::iOutput = &std::clog;	// Par défaut
bool 			AMyStream::autoEndl = true;		    // autoEndl yes
bool			AMyStream::autoSpace = true;		// autoSpace yes

AMyStream::AMyStream():
	_nbElems(0),
	_ended(false),
	_autoSpace(true)
{
	this->_iOutput = iOutput;
}

AMyStream::AMyStream(std::ostream* stream, bool autoSp):
	_nbElems(0),
	_ended(false),
	_autoSpace(autoSp)
{
	if (stream)
		this->_iOutput = stream;
	else
		this->_iOutput = iOutput;
}

AMyStream::AMyStream(bool autoSp):
	_nbElems(0),
	_ended(false),
	_autoSpace(autoSp)
{
	this->_iOutput = iOutput;
}

AMyStream::~AMyStream()
{
	if (autoEndl && !this->_ended)
		*this->_iOutput << std::endl;
}

void AMyStream::setAutoSpace(bool value)
{
	autoSpace = value;
}

void AMyStream::setAutoEndl(bool value)
{
	autoEndl = value;
}

void AMyStream::setOutput(std::ostream* value)
{
	iOutput = value;
}

// Implémentations des opérateurs (appellent le template)
AMyStream &AMyStream::operator<<(const std::string& value)
{
	return _output(value);
}

AMyStream &AMyStream::operator<<(const char* value)
{
	return _output(value);
}

AMyStream &AMyStream::operator<<(int value)
{
	return _output(value);
}

AMyStream &AMyStream::operator<<(float value)
{
	return _output(value);
}

AMyStream &AMyStream::operator<<(bool value)
{
	return _output(value);
}

AMyStream &AMyStream::operator<<(std::ostream& (*manip)(std::ostream&))
{
	*this->_iOutput << manip;
	if (manip == static_cast<std::ostream& (*)(std::ostream&)>(std::endl))
		this->_ended = true;
	return *this;
}
