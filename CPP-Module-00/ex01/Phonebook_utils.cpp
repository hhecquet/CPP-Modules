/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 07:49:05 by marvin            #+#    #+#             */
/*   Updated: 2025/04/28 13:01:48 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook_utils.hpp"

std::string	add_spaces(int n)
{
	std::string	str;

	while (n--)
		str.append(" ");
	return (str);
}

std::string	fix_width(std::string str, long unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int	search_utils(Contact contacts[8])
{
	char		c;
	int			i;
	std::string	str;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	c = '0';
	i = 0;
	while (++c <= '8')
	{
		if (contacts[c - 1 - '0'].get_first().size() && ++i)
		{
			str = c;
			str = fix_width(str, 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].get_first(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].get_last(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].get_nick(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			std::cout << "|" << std::endl;
		}
	}
	std::cout << " ------------------------------------------- " << std::endl;
	return (i);
}