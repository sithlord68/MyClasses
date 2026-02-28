/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyTools.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:23:53 by pjolidon          #+#    #+#             */
/*   Updated: 2026/02/28 22:48:38 by pjolidon         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MyTools.hpp"

std::string MyTools::outputThousandsAndPrecision(double value, int precision)
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(precision) << value;
    std::string str = ss.str();
    
    // Séparer la partie entière de la partie décimale
    size_t dotPos = str.find('.');
    std::string intPart = str.substr(0, dotPos);
    std::string decPart = str.substr(dotPos);
    
    // Ajouter les séparateurs de milliers dans la partie entière
    std::string result;
    int len = intPart.length();
    for (int i = 0; i < len; i++)
    {
        if (i > 0 && (len - i) % 3 == 0)
            result += '\'';
        result += intPart[i];
    }
    
    return result + decPart;
}

char	MyTools::toLower( char c )
{
	if ( c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	return c;
}

void	MyTools::toLower( std::string *str )
{
	size_t	len = (*str).length();

	for (size_t i = 0; i < len; i++)
	{
		if ( (*str)[i] >= 'A' && (*str)[i] <= 'Z')
			(*str)[i] += 'a' - 'A';
	}
}

char	MyTools::toUpper( char c )
{
	if ( c >= 'a' && c <= 'z')
		return c - 'a' + 'A';
	return c;
}

void	MyTools::toUpper( std::string *str )
{
	size_t	len = (*str).length();

	for (size_t i = 0; i < len; i++)
	{
		if ( (*str)[i] >= 'a' && (*str)[i] <= 'z')
			(*str)[i] += 'A' - 'a';
	}
}

bool	MyTools::isEntier( float f )
{
	long long	ll = static_cast<long long>(f);
	if (static_cast<float>(ll) == f)
		return true;
	return false;
}

bool	MyTools::isEntier( double d )
{
	long long	ll = static_cast<long long>(d);
	if (static_cast<float>(ll) == d)
		return true;
	return false;
}