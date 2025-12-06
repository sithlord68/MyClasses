/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDebug.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:35:17 by pjolidon          #+#    #+#             */
/*   Updated: 2025/12/06 22:06:06 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MyDebug.hpp"

struct MyDebugStaticInit {
	static std::ostream* initOutput() {
		static bool first = true;
		static std::ostream* defaultOut = &std::clog;
		if (first)
			first = false;
		return defaultOut;
	}
};

MyDebug::MyDebug() : AMyStream()
{
	this->_iOutput = MyDebugStaticInit::initOutput();
}

MyDebug::MyDebug(std::ostream* stream, bool autoSp) 
	: AMyStream(stream, autoSp)
{
	if (!stream)
		this->_iOutput = MyDebugStaticInit::initOutput();
}

MyDebug::MyDebug(bool autoSp) : AMyStream(autoSp)
{
	this->_iOutput = MyDebugStaticInit::initOutput();
}

MyDebug::~MyDebug()
{
	// destructor
}

MyDebug &MyDebug::operator<<(const std::string& value)
{
	if (!MYDEBUG)
		return *this;
	return this->_output(value, false);
}

MyDebug &MyDebug::operator<<(const char* value)
{
	if (!MYDEBUG) return *this;
	return this->_output(value, false);
}

MyDebug &MyDebug::operator<<(int value)
{
	if (!MYDEBUG) return *this;
	return this->_output(value, false);
}

MyDebug &MyDebug::operator<<(float value)
{
	if (!MYDEBUG) return *this;
	return this->_output(value, false);
}

MyDebug &MyDebug::operator<<(bool value)
{
	if (!MYDEBUG) return *this;
	return this->_output(value, false);
}

MyDebug &MyDebug::operator<<(std::ostream& (*manip)(std::ostream&))
{
	if (!MYDEBUG) return *this;
	
	*this->_iOutput << manip;
	if (manip == static_cast<std::ostream& (*)(std::ostream&)>(std::endl))
		this->_ended = true;
	return *this;
}

MyDebug& MyDebug::withContext(const std::string& context)
{
	if (MYDEBUG && this->_nbElems == 0)
	{
		*this->_iOutput << "[" << context << "] ";
		this->_nbElems++;
	}
	return *this;
}
