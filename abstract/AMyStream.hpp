/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMyStream.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:56:54 by pjolidon          #+#    #+#             */
/*   Updated: 2026/01/21 11:23:16 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>

#ifndef AMYSTREAM_HPP
# define AMYSTREAM_HPP

class AMyStream
{

	public:

		static void	setAutoSpace( bool value );
		static void	setAutoEndl( bool value );
		static void	setOutput( std::ostream *value );

		AMyStream( void );
		AMyStream( std::ostream* stream, bool autoSpace );
		AMyStream( bool autoSpace );

		AMyStream &operator<<(std::string value);
		AMyStream &operator<<(int value);
		AMyStream &operator<<(unsigned int value);
		AMyStream &operator<<(size_t value);
		AMyStream &operator<<(float value);
		AMyStream &operator<<(double value);
		AMyStream &operator<<(bool value);
		AMyStream &operator<<(char* value);
		AMyStream &operator<<(char const *value);
		AMyStream &operator<<(char value);

		AMyStream & operator<<(std::ostream& (*manip)(std::ostream&));

		void setHeader( std::string  const &header );

	protected:

		virtual	~AMyStream( void );						// canon

		int					_nbElems;
		std::ostream		*_iOutput;
		bool				_ended;
		static bool			_autoEndl;
		static bool			_autoSpace;
		static std::ostream	*iOutput;
		static std::string	_header;

	private:
		AMyStream( AMyStream const &rhs );				// canon
		virtual AMyStream &operator=( AMyStream const &rhs ) = 0;	// canon

};


#endif
