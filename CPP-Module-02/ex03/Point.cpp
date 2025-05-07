/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:02:54 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 09:02:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::Point(float const x, float const y) : _x(x), _y(y) {
}

Point::Point(Point const &other) : _x(other._x), _y(other._y) {
}

Point &Point::operator=(Point const &other) {
    if (this != &other) {
        // _x and _y are const, so we cannot assign them
        // this->_x = other._x;
        // this->_y = other._y;
    }
    return *this;
}

Point::~Point(void) {
}

Fixed Point::getX(void) const {
    return this->_x;
}

Fixed Point::getY(void) const {
    return this->_y;
}