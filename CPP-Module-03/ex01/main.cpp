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

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap Gero("Gero");
	ClapTrap Sherpa("Sherpa");
	ScavTrap Marie("Marie");

	Marie.attack("Sherpa");
	Sherpa.takeDamage(20);
	Gero.attack("Sherpa");
	Sherpa.takeDamage(0);
	Sherpa.beRepaired(1);
	Marie.guardGate();
	Gero.attack("Marie");
	Marie.takeDamage(0);
	return 0;
}