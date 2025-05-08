/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:06:32 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 14:34:42 by hhecquet         ###   ########.fr       */
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
    delete dog;
    delete cat;

    std::cout << "\n---- Array of Animals Test ----" << std::endl;
    const int size = 10;
    Animal* zoo[size];

    for (int i = 0; i < size / 2; ++i) {
        zoo[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i) {
        zoo[i] = new Cat();
    }
    for (int i = 0; i < size; ++i) {
        delete zoo[i];
    }

    std::cout << "\n---- Deep Copy Test ----" << std::endl;
    Dog basicDog;
    {
        Dog copiedDog = basicDog;
    }
    Cat basicCat;
    {
        Cat copiedCat;
        copiedCat = basicCat;
    }
	std::cout << "\n---- Brain Content Deep Copy Check ----" << std::endl;
	basicDog.setIdeas("Chase cats", 0);
	Dog copyDog = basicDog;
	copyDog.setIdeas("Sleep", 0);
	std::cout << "BasicDog idea: " << basicDog.getIdeas(0) << std::endl;
	std::cout << "CopyDog idea: " << copyDog.getIdeas(0) << std::endl;
    return 0;
}