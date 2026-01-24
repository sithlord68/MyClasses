/*   AMyStream.hpp                                      :+:      :+:    :+:   */

#include <string>
#include <iostream>

#ifndef AMYSTREAM_HPP
# define AMYSTREAM_HPP

class AMyStream
{

	public:


		AMyStream( void );									// canon
		AMyStream( bool const autoSpace );
		AMyStream( std::ostream* stream, bool autoSpace );
		AMyStream( std::ostream* stream, bool autoSpace, bool autoEndl );
		AMyStream( std::ostream* stream, bool autoSpace, bool autoEndl, char separator );

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

		static void	setOutput( std::ostream *value );
		static void setAutoSpace( bool const autoSpace );
		static void setAutoEndl( bool const autoEndl );
		static void setHeader( std::string  const &header );
		static void	setSeparator( char const c );
		static void	setDefaults( std::ostream* stream, std::string  const &header,
					bool const autoSpace, bool const autoEndl);

	protected:

		std::ostream		*_output;
		bool				_autoEndl;
		bool				_autoSpace;
		char				_separator;
		int					_nbElems;
		bool				_ended;
	
		static bool			_autoSpaceClass;
		static bool			_autoEndlClass;
		static std::ostream	*_outputClass;
		static std::string	_header;
		static char			_separatorClass;

		static bool			_defaultSet;

		virtual	~AMyStream( void ) = 0;					// canon

	private:

		AMyStream( AMyStream const &rhs );				// canon unused
		AMyStream &operator=( AMyStream const &rhs );	// canon unused

};

#include "AMyStream.tpp"

#endif
