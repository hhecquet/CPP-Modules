/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:03 by hhecquet          #+#    #+#             */
/*   Updated: 2025/05/05 13:05:53 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void){
	this->_value = 0;
}

Fixed::Fixed(const Fixed& other){
	this->_value = other._value;
}

Fixed::Fixed(const int i){
	this->_value = i << _bits;
}

Fixed::Fixed(const float flo){
	this->_value = roundf(flo * (1 << _bits));
}

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other){
		this->_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void){
}

bool Fixed::operator>(const Fixed& other) const{
	return (this->_value > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const{
	return (this->_value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const{
	return (this->_value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const{
	return (this->_value <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const{
	return (this->_value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const{
	return (this->_value != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other){
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other){
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other){
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other){
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	return (a > b) ? a : b;
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

Fixed& Fixed::operator++() {
    ++this->_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++this->_value;
    return temp;
}

Fixed& Fixed::operator--() {
    --this->_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --this->_value;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}