/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 07:51:08 by marvin            #+#    #+#             */
/*   Updated: 2025/04/17 07:51:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Phonebook_utils.hpp"

int	main(void)
{
	Phonebook 	phonebook;
	std::string	str;

	while (str != "EXIT")
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		if (str == "ADD")
            phonebook.add();
		else if (str == "SEARCH")
			phonebook.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}