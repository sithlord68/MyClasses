/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyDisplay.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:34:30 by pjolidon          #+#    #+#             */
/*   Updated: 2025/12/06 22:02:22 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AMyStream.hpp"

#ifndef MYDISPLAY_HPP
# define MYDISPLAY_HPP

class MyDisplay : public AMyStream
{
	public:
		MyDisplay();
		MyDisplay(std::ostream* stream, bool autoSp);
		explicit MyDisplay(bool autoSp);
		~MyDisplay();

	private:
		struct StaticInit
		{
			static std::ostream* getDefaultOutput();
		};
		
		MyDisplay(const MyDisplay&);
		MyDisplay& operator=(const MyDisplay&);
};

#endif