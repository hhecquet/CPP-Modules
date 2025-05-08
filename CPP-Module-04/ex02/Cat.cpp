/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:16:25 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 14:45:55 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
    std::cout << "Cat Default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat Copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat(void) {
    std::cout << "Cat Destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound(void) const {
    std::cout << "Meow Meow!" << std::endl;
}

void Cat::setIdeas(const std::string& idea, int index) {
    this->brain->setIdeas(idea, index);
}

std::string Cat::getIdeas(int index) const {
    return this->brain->getIdeas(index);
}