/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:30:02 by marvin            #+#    #+#             */
/*   Updated: 2025/05/20 10:30:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void){
    srand(time(0));
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p){
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p){
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (...) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (...) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            } catch (...) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}