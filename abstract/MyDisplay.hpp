/*   MyDisplay.hpp                                      :+:      :+:    :+:   */
/*   Created: 2025/11/06 14:34:30 by pjolidon          #+#    #+#             */

#include <string>
#include <iostream>
#include <typeinfo>

#ifndef MYDISPLAY_HPP
# define MYDISPLAY_HPP


#include "AMyStream.hpp"

class MyDisplay: public AMyStream
{
	public:

		MyDisplay( void );					// canon default constructor to set out to std::clog
		MyDisplay( bool const autoSpace );
		MyDisplay( std::ostream* stream, bool autoSpace );
		virtual ~MyDisplay( void );			// canon destructor
		MyDisplay &operator<<(std::string value);
		MyDisplay &operator<<(int value);
		MyDisplay &operator<<(unsigned int value);
		MyDisplay &operator<<(size_t value);
		MyDisplay &operator<<(float value);
		MyDisplay &operator<<(double value);
		MyDisplay &operator<<(bool value);
		MyDisplay &operator<<(char* value);
		MyDisplay &operator<<(char const *value);
		MyDisplay &operator<<(char value);

	private:

		MyDisplay( MyDisplay &rhs);				// canon copy constructor
		MyDisplay &operator=( MyDisplay &rhs );	// canon = operator

};

#endif

