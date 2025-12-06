/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDisplay.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:34:30 by pjolidon          #+#    #+#             */
/*   Updated: 2025/12/06 11:51:12 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>

#ifndef MYDISPLAY_HPP
# define MYDISPLAY_HPP

class MyDisplay
{
	public:

		MyDisplay( void );									// canon default constructor
		~MyDisplay( void );									// canon destructor

		MyDisplay( MyDisplay &rhs);								// canon copy constructor
		MyDisplay &			operator=( MyDisplay &rhs );	// canon = operator

		void				setAutoSpace( bool value );
		void				setAutoEndl( bool value );
		void				setOutput( std::ostream *value );

		MyDisplay( std::ostream* stream, bool autoSpace );

		MyDisplay &operator<<(std::string value);
		MyDisplay &operator<<(int value);
		MyDisplay &operator<<(float value);
		MyDisplay &operator<<(bool value);
		MyDisplay &operator<<(const char* value);

		MyDisplay & operator<<(std::ostream& (*manip)(std::ostream&));   // pour operteurs de flux (fonction) tels que std::endl

	private:

		int					_nbElems;
		std::ostream		*_iOutput;
		bool				_ended;
		bool				_autoSpace;
		static bool			autoEndl;
		static bool			autoSpace;
		static std::ostream	*iOutput;

};

#endif
