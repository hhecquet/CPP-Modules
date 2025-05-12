/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:55:59 by hhecquet          #+#    #+#             */
/*   Updated: 2025/05/12 11:24:41 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;

		for (int i = 0; i < 4; ++i)
		{
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = NULL;
			}

			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		delete _inventory[i];
}

std::string const & Character::getName() const { return _name; }

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!_inventory[i])
		{
			std::cout << "* " << this->getName() << " equipping " << m->getType() << " *" << std::endl;
			_inventory[i] = m;
			break;
		}
		else if (i == 3)
		{
			std::cout << "* " << this->getName() << " can't equip " << m->getType() << " *" << std::endl;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (!_inventory[idx])
		{
			std::cout << "* " << this->getName() << " as nothing equiped at " << idx << " *" << std::endl;
			return ;
		}
		std::cout << "* " << this->getName() << " unequipping " << _inventory[idx]->getType() << " *" << std::endl;
		_inventory[idx] = NULL;
	}
	else
	{
		std::cout << "* " << this->getName() << " can't unequip " << idx << " *" << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "* " << this->getName() << " can't use " << idx << " *" << std::endl;
}
