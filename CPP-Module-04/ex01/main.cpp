/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:06:32 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 16:06:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "---- Basic Creation and Deletion Test ----" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    delete dog; // Should not leak
    delete cat;

    std::cout << "\n---- Array of Animals Test ----" << std::endl;
    const int size = 10;
    Animal* zoo[size];

    // Fill first half with Dogs, second half with Cats
    for (int i = 0; i < size / 2; ++i) {
        zoo[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i) {
        zoo[i] = new Cat();
    }

    // Delete all animals (as Animals, to test virtual destructors)
    for (int i = 0; i < size; ++i) {
        delete zoo[i];
    }

    std::cout << "\n---- Deep Copy Test ----" << std::endl;
    Dog basicDog;
    {
        Dog copiedDog = basicDog; // Should trigger copy constructor and deep copy
    } // copiedDog goes out of scope: Brain must be deleted

    Cat basicCat;
    {
        Cat copiedCat;
        copiedCat = basicCat; // Should trigger copy assignment and deep copy
    } // copiedCat goes out of scope

    return 0;
}