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

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Gero("Gero");
    ClapTrap Sherpa("Sherpa");

    Gero.attack("Sherpa");
    Sherpa.takeDamage(0);
    Sherpa.beRepaired(1);
    Gero.attack("Sherpa");
    Sherpa.takeDamage(0);
    Sherpa.attack("Gero");
    Gero.takeDamage(0);
    Gero.attack("Sherpa");
    Sherpa.takeDamage(0);
    Sherpa.beRepaired(1);
    Gero.beRepaired(1);
    Sherpa.beRepaired(1);
    Gero.beRepaired(1);
    Sherpa.beRepaired(1);
    Gero.beRepaired(1);
    Sherpa.beRepaired(1);
    Gero.beRepaired(1);
    Sherpa.beRepaired(1);
    Gero.beRepaired(1);
    Sherpa.beRepaired(1);
    Gero.beRepaired(1);
    Sherpa.beRepaired(1);
    Gero.beRepaired(1);
    Sherpa.beRepaired(1);
    Gero.beRepaired(1);
    return 0;
}