/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:51:24 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 09:51:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    ClapTrap Gero("Gero");
	ClapTrap Sherpa("Sherpa");
	ScavTrap Marie("Marie");
    FragTrap Yoshi("Yoshi");

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
    return 0;
}