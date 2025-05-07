/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:15:49 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 16:15:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal(void) {
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Grrr..." << std::endl;
}

std::string Animal::getType(void) const {
    return this->type;
}