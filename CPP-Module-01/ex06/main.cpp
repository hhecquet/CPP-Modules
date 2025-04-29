/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:23:20 by marvin            #+#    #+#             */
/*   Updated: 2025/04/29 15:23:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "wrong number of argument" << std::endl;
		return 0;
	}
	std::string level = argv[1];
	Harl harl;
	harl.complain(level);
	return 0;
}