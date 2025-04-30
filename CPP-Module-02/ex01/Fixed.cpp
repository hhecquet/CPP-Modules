/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:03 by hhecquet          #+#    #+#             */
/*   Updated: 2025/04/30 12:58:40 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw){
	this->_rawBits = raw;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float flo){
	std::cout << "Float constructor called" << std::endl;
	this->_floatBits = flo;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator<<(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		this->_rawBits = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const{
	
}

int Fixed::toInt(void) const{
	
}