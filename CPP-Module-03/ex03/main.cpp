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

#include "DiamondTrap.hpp"


int main() {
    DiamondTrap dt("Diamond");

    // Specify which attack function to use (ScavTrap or FragTrap)
    dt.ScavTrap::attack("enemy");  // Call attack from ScavTrap
    dt.takeDamage(20);  // This calls ClapTrap's takeDamage (since both inherit from ClapTrap)

    // Specify which attack function to use
    dt.FragTrap::attack("enemy");  // Call attack from FragTrap
    dt.takeDamage(20);  // Again, calls the common takeDamage function from ClapTrap

    // Specify which beRepaired function to use (both ScavTrap and FragTrap inherit from ClapTrap)
    dt.beRepaired(10);  // Calls the common beRepaired function from ClapTrap

    // Call the special function for DiamondTrap
    dt.whoAmI();

    return 0;
}

// #include "FragTrap.hpp"

// int main() {
//     ClapTrap Gero("Gero");
// 	ClapTrap Sherpa("Sherpa");
// 	ScavTrap Marie("Marie");
//     FragTrap Yoshi("Yoshi");

//     Yoshi.attack("Marie");
//     Marie.takeDamage(30);
//     Marie.attack("Sherpa");
// 	Sherpa.takeDamage(20);
// 	Gero.attack("Sherpa");
// 	Sherpa.takeDamage(0);
// 	Sherpa.beRepaired(1);
// 	Marie.guardGate();
// 	Gero.attack("Marie");
// 	Marie.takeDamage(0);
//     Yoshi.highFivesGuys();
//     return 0;
// }