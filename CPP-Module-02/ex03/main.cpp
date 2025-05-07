/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:09 by hhecquet          #+#    #+#             */
/*   Updated: 2025/04/30 12:36:27 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);
	Point pointInside(2, 1);
	Point pointOutside(6, 6);
	Point pointOnEdge(0, 0);

	if (bsp(a, b, c, pointInside)) {
		std::cout << "The point is inside the triangle." << std::endl;
	} else {
		std::cout << "The point is outside or on the edge of the triangle." << std::endl;
	}
	if (bsp(a, b, c, pointOutside)) {
		std::cout << "The point is inside the triangle." << std::endl;
	} else {
		std::cout << "The point is outside or on the edge of the triangle." << std::endl;
	}
	if (bsp(a, b, c, pointOnEdge)) {
		std::cout << "The point is inside the triangle." << std::endl;
	} else {
		std::cout << "The point is outside or on the edge of the triangle." << std::endl;
	}
	return 0;
}