/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:51:24 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 14:02:23 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    ClapTrap Gero("Gero");
	ClapTrap Sherpa("Sherpa");
	ScavTrap Marie("Marie");
    FragTrap Yoshi("Yoshi");
	DiamondTrap Toad("Toad");

	Toad.ScavTrap::attack("Gero");
	Gero.takeDamage(20);
    Yoshi.attack("Marie");
    Marie.takeDamage(30);
    Marie.attack("Sherpa");
	Sherpa.takeDamage(20);
	Gero.attack("Sherpa");
	Sherpa.takeDamage(0);
	Sherpa.beRepaired(1);
	Marie.guardGate();
	Gero.attack("Marie");
	Marie.takeDamage(0);
    Yoshi.highFivesGuys();
	Toad.whoAmI();
    return 0;
}