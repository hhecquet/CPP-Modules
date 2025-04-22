/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:27:45 by hhecquet          #+#    #+#             */
/*   Updated: 2025/04/22 10:43:52 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    Zombie* heapZ = newZombie("HeapZ");
    heapZ->announce();
    
    randomChump("StackZ");

    delete heapZ; 
    return 0;
}