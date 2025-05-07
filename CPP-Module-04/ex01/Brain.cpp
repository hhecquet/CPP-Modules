/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:58:32 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 16:58:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain(void) {
    std::cout << "Brain Destructor called" << std::endl;
}

void Brain::setIdeas(std::string idea, int index) {
    if (index >= 0 && index < 100) {
        this->ideas[index] = idea;
    } else {
        std::cout << "Index out of range" << std::endl;
    }
}

std::string Brain::getIdeas(int index) const {
    if (index >= 0 && index < 100) {
        return this->ideas[index];
    } else {
        std::cout << "Index out of range" << std::endl;
        return "";
    }
}