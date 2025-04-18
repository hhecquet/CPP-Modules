/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 07:17:16 by marvin            #+#    #+#             */
/*   Updated: 2025/04/17 07:17:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Phonebook_utils.hpp"

Phonebook::Phonebook(void)
{
}

Phonebook::~Phonebook(void)
{
}

Contact	Phonebook::get_contact(int index)
{
	return (this->contacts[index % 8]);
}

void	Phonebook::add(void)
{
	std::string	str;

	str = "";
    if (this->index < 8)
	{
        while (!std::cin.eof() && str == "")
    	{
    		std::cout << "First name: ";
    		if (std::getline(std::cin, str) && str != "")
    			this->contacts[this->index % 8].set_first(str);
    	}
    	str = "";
    	while (!std::cin.eof() && str == "")
    	{
    		std::cout << "Last name: ";
    		if (std::getline(std::cin, str) && str != "")
    			this->contacts[this->index % 8].set_last(str);
    	}
    	str = "";
    	while (!std::cin.eof() && str == "")
    	{
    		std::cout << "Nickname: ";
    		if (std::getline(std::cin, str) && str != "")
    			this->contacts[this->index % 8].set_nick(str);
    	}
    	str = "";
    	while (!std::cin.eof() && str == "")
    	{
    		std::cout << "Phone number: ";
    		if (std::getline(std::cin, str) && str != "")
    			this->contacts[this->index % 8].set_number(str);
    	}
    	str = "";
    	while (!std::cin.eof() && str == "")
    	{
    		std::cout << "Darkest secret: ";
    		if (std::getline(std::cin, str) && str != "")
    			this->contacts[this->index % 8].set_secret(str);
    	}
    	this->index++;
    }
    else
        std::cout << "Phonebook is full" << std::endl;
}

void	Phonebook::print(Contact contact)
{
	std::cout << std::endl << "Requesting contact information..." << std::endl;
	if (!contact.get_first().size())
	{
		std::cout << "Failed to get info for this contact" << std::endl;
		return ;
	}
	std::cout << "First Name: " << contact.get_first() << std::endl;
	std::cout << "Last Name: " << contact.get_last() << std::endl;
	std::cout << "Nickname: " << contact.get_nick() << std::endl;
	std::cout << "Phone Number: " << contact.get_number() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
}

void	Phonebook::search(void)
{
	std::string	str;

	if (!search_utils(this->contacts))
	{
		std::cout << std::endl << "Phonebook is empty!" << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
					this->contacts[str[0] - 1 - '0'].get_first().size())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		this->print(this->contacts[str[0] - 1 - '0']);
}