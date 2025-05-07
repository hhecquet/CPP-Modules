/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:10:52 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 12:10:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
    std::cout << "FragTrap Default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap Constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->_hitPoints > 0 && this->_energyPoints > 0) {
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else if (this->_hitPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " is dead and cannot attack." << std::endl;
    } else {
        std::cout << "FragTrap " << this->_name << " has no energy left to attack." << std::endl;
    }
}

void FragTrap::highFivesGuys(void) {
    if (this->_hitPoints > 0 && this->_energyPoints > 0) {
        std::cout << "FragTrap " << this->_name << " is requesting a high five!" << std::endl;
    } else if (this->_hitPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " is dead and cannot request a high five." << std::endl;
    } else {
        std::cout << "FragTrap " << this->_name << " has no energy left to request a high five." << std::endl;
    }
}