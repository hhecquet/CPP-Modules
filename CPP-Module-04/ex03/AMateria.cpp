/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:06:05 by hhecquet          #+#    #+#             */
/*   Updated: 2025/05/08 15:07:09 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src) {
	std::cout << "AMateria Copy constructor called" << std::endl;
	*this = src;
}

AMateria& AMateria::operator=(AMateria const &other) {
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria use function called on " << target.getName() << std::endl;
}

