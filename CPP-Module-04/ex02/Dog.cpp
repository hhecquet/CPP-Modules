/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:17:09 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 14:45:46 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
    std::cout << "Dog Default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog(void) {
    std::cout << "Dog Destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound(void) const {
    std::cout << "Woof Woof!" << std::endl;
}

void Dog::setIdeas(const std::string& idea, int index) {
    this->brain->setIdeas(idea, index);
}

std::string Dog::getIdeas(int index) const {
    return this->brain->getIdeas(index);
}