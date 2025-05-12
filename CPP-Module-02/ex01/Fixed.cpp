/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:03 by hhecquet          #+#    #+#             */
/*   Updated: 2025/05/12 08:50:58 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void){
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int i){
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << _bits;
}

Fixed::Fixed(const float flo){
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(flo * (1 << _bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt( void ) const {
	return (this->_value >> _bits);
}

float Fixed::toFloat( void ) const {
	return ((float)this->_value / (1 << _bits));
}


int Fixed::getRawBits(void) const{
	return (this->_value);
}

void Fixed::setRawBits(int const raw){
	this->_value = raw;
}