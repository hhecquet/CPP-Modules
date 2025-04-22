/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:51:38 by hhecquet          #+#    #+#             */
/*   Updated: 2025/04/22 13:12:55 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon &weapon;	
public:
	HumanB(std::string name);
	~HumanB();
	void attack(void);
	void setWeapon(Weapon &weapon);
};

#endif