/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:23:23 by marvin            #+#    #+#             */
/*   Updated: 2025/04/29 15:23:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// class Harl
// {
// 	private :
// 		void debug(void);
// 		void info(void);
// 		void warning(void);
// 		void error(void);
// 	public :
// 		Harl(void);
// 		~Harl(void);
// 		void complain( std::string level );
// };

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
	Harl::info();
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
	<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
	Harl::warning();
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
	<< "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl << std::endl;
	Harl::error();
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
	<< "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
	static const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	static const HarlFt fns[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (size_t i = 0; i < 4; ++i) {
		if (level == levels[i]) {
			(this->*fns[i])();
			return;
		}
	}
	std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
}
//You must use, and maybe discover, the switch statement in this exercise.