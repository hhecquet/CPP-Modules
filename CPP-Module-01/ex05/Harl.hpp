/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:24:54 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 08:56:17 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>

class Harl
{
	private :
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		typedef void (Harl::*HarlFt)(void);
		//static void (Harl::*fns[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; in Harl.cpp
	public :
		Harl(void);
		~Harl(void);
		void complain(std::string level);
};

#endif