/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDisplay.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:35:17 by pjolidon          #+#    #+#             */
/*   Updated: 2025/12/06 22:05:38 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MyDisplay.hpp"

std::ostream* MyDisplay::StaticInit::getDefaultOutput()
{
	static bool first = true;
	static std::ostream* defaultOut = &std::cout;
	if (first)
		first = false;
	return defaultOut;
}

MyDisplay::MyDisplay() : AMyStream()
{
	this->_iOutput = StaticInit::getDefaultOutput();
}

MyDisplay::MyDisplay(std::ostream* stream, bool autoSp) 
	: AMyStream(stream, autoSp)
{
	if (!stream)
		this->_iOutput = StaticInit::getDefaultOutput();
}

MyDisplay::MyDisplay(bool autoSp) : AMyStream(autoSp)
{
	this->_iOutput = StaticInit::getDefaultOutput();
}

MyDisplay::~MyDisplay()
{
	// destructor
}
