/*   MyDebug.hpp                                        :+:      :+:    :+:   */
/*   Created: 2025/11/06 14:34:30 by pjolidon          #+#    #+#             */

#include <string>
#include <iostream>
#include <typeinfo>

#ifndef MYDEBUG_HPP
# define MYDEBUG_HPP

# ifndef MYDEBUG
#  define MYDEBUG 0
# endif

#include "AMyStream.hpp"

class MyDebug: public AMyStream
{
	public:

		MyDebug( void );					// canon default constructor to set out to std::clog
		MyDebug::MyDebug(bool autoSpace);	// to set out to std::clog
		virtual ~MyDebug( void );			// canon destructor
		MyDebug &operator<<(std::string value);
		MyDebug &operator<<(int value);
		MyDebug &operator<<(unsigned int value);
		MyDebug &operator<<(size_t value);
		MyDebug &operator<<(float value);
		MyDebug &operator<<(double value);
		MyDebug &operator<<(bool value);
		MyDebug &operator<<(char* value);
		MyDebug &operator<<(char const *value);
		MyDebug &operator<<(char value);

	private:

		MyDebug( MyDebug &rhs);				// canon copy constructor
		MyDebug &operator=( MyDebug &rhs );	// canon = operator

};

#endif
