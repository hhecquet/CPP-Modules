/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:04:38 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 09:04:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed ABC = Fixed(0.5f) * (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
    Fixed ABP = Fixed(0.5f) * (a.getX() * (b.getY() - point.getY()) + b.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - b.getY()));
    Fixed BCP = Fixed(0.5f) * (b.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - b.getY()) + point.getX() * (b.getY() - c.getY()));
    Fixed CAP = Fixed(0.5f) * (c.getX() * (a.getY() - point.getY()) + a.getX() * (point.getY() - c.getY()) + point.getX() * (c.getY() - a.getY()));
    if (ABC == ABP + BCP + CAP && ABP > 0 && BCP > 0 && CAP > 0){
        return true;
    }
    return false;
}