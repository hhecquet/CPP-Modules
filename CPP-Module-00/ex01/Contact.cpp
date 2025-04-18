/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 07:12:11 by marvin            #+#    #+#             */
/*   Updated: 2025/04/17 07:12:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string	Contact::get_first(void) const
{
	return (this->first_name);
}

std::string	Contact::get_last(void) const
{
	return (this->last_name);
}

std::string	Contact::get_nick(void) const
{
	return (this->nickname);
}

std::string	Contact::get_number(void) const
{
	return (this->phone_number);
}

std::string	Contact::get_secret(void) const
{
	return (this->darkest_secret);
}

void	Contact::set_first(std::string str)
{
	this->first_name = str;
}

void	Contact::set_last(std::string str)
{
	this->last_name = str;
}

void	Contact::set_nick(std::string str)
{
	this->nickname = str;
}

void	Contact::set_number(std::string str)
{
	this->phone_number = str;
}

void	Contact::set_secret(std::string str)
{
	this->darkest_secret = str;
}