/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:06:32 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 14:19:56 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal*  meta = new Animal();
    const Animal*  j    = new Dog();
    const Animal*  i    = new Cat();

    std::cout << "j is a " << j->getType() << std::endl;
    std::cout << "i is a " << i->getType() << std::endl;
    std::cout << "meta is a " << meta->getType() << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();
	std::cout << "wa is a " << wa->getType() << std::endl;
    std::cout << "wc is a " << wc->getType() << std::endl;
    wa->makeSound();
    wc->makeSound();
    delete wa;
    delete wc;
	const WrongCat* wca = new WrongCat();
	std::cout << "wca is a " << wca->getType() << std::endl;
	wca->makeSound();
	delete wca;
    return 0;
}