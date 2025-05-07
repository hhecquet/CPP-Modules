/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:51:18 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 09:51:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	} else if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack." << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name << " has no energy left to attack." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " lose " << amount << " hit points! "  << std::endl;
		if (amount >= this->_hitPoints)
			amount = this->_hitPoints;
		this->_hitPoints -= amount;
	} else if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " regains " << amount << " hit points!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	} else if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead and cannot repairs itself." << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name << " has no energy left to repairs itself." << std::endl;
	}
}