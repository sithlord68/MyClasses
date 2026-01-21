/*   AMyStream.hpp                                      :+:      :+:    :+:   */

#include <string>
#include <iostream>

#ifndef AMYSTREAM_HPP
# define AMYSTREAM_HPP

class AMyStream
{

	public:

		void	setAutoSpace( bool value );
		void	setAutoEndl( bool value );
		void	setOutput( std::ostream *value );

		AMyStream( void );									// canon
		AMyStream( std::ostream* stream, bool autoSpace );
		AMyStream( bool autoSpace );

		virtual AMyStream &operator<<(std::string value);
		virtual AMyStream &operator<<(int value);
		virtual AMyStream &operator<<(unsigned int value);
		virtual AMyStream &operator<<(size_t value);
		virtual AMyStream &operator<<(float value);
		virtual AMyStream &operator<<(double value);
		virtual AMyStream &operator<<(bool value);
		virtual AMyStream &operator<<(char* value);
		virtual AMyStream &operator<<(char const *value);
		virtual AMyStream &operator<<(char value);

		AMyStream & operator<<(std::ostream& (*manip)(std::ostream&));

		static void setHeader( std::string  const &header );

	protected:

		virtual	~AMyStream( void ) = 0;								// canon

		int					_nbElems;
		std::ostream		*_iOutput;
		bool				_ended;
		bool				_autoEndl;
		bool				_autoSpace;
		std::ostream		*iOutput;
		static std::string	_header;

	private:
		AMyStream( AMyStream const &rhs );						// canon
		AMyStream &operator=( AMyStream const &rhs );	// canon

};


#endif
