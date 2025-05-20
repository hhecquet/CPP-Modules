/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:33:00 by marvin            #+#    #+#             */
/*   Updated: 2025/05/20 10:33:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    Base *base = generate();
    std::cout << "Identifying using pointer: ";
    identify(base);
    std::cout << "Identifying using reference: ";
    identify(*base);
    delete base;
    return 0;
}