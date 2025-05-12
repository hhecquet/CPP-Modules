/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:55:11 by hhecquet          #+#    #+#             */
/*   Updated: 2025/05/12 11:29:24 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	std::cout << "---- Test 1: Basic Creation and Destruction ----" << std::endl;
	IMateriaSource* src1 = new MateriaSource();
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());
	ICharacter* me1 = new Character("me");
	AMateria* tmp1;
	tmp1 = src1->createMateria("ice");
	me1->equip(tmp1);
	tmp1 = src1->createMateria("cure");
	me1->equip(tmp1);
	ICharacter* bob1 = new Character("bob");
	me1->use(0, *bob1);
	me1->use(1, *bob1);
	delete bob1;
	delete me1;
	delete src1;

	std::cout << "---- Test 2: Deep Copy and Assignment ----" << std::endl;
    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());
    ICharacter* me2 = new Character("me");
    AMateria* tmp2;
    tmp2 = src2->createMateria("ice");
    me2->equip(tmp2);
    tmp2 = src2->createMateria("cure");
    me2->equip(tmp2);
	ICharacter* copy = new Character(*dynamic_cast<Character*>(me2));
    ICharacter* assign = new Character("assign");
    *assign = *me2;
    copy->use(0, *assign);
    copy->use(1, *assign);
    delete copy;
    delete assign;
    delete me2;
    delete src2;

	std::cout << "---- Test 3: Equip/Unequip and Out of Bound ----" << std::endl;
	IMateriaSource* src3 = new MateriaSource();
	src3->learnMateria(new Ice());
	src3->learnMateria(new Cure());
	ICharacter* me3 = new Character("me");
	AMateria* tmp3;
	tmp3 = src3->createMateria("ice");
	me3->equip(tmp3);
	tmp3 = src3->createMateria("cure");
	me3->equip(tmp3);
	tmp3 = src3->createMateria("ice");
	me3->equip(tmp3);
	tmp3 = src3->createMateria("cure");
	me3->equip(tmp3);
	tmp3 = src3->createMateria("ice");
	me3->equip(tmp3);
	me3->use(0, *me3);
	me3->use(1, *me3);
	me3->unequip(0);
	me3->use(0, *me3);
	delete me3;
	delete src3;

	std::cout << "---- Test 4: Invalid Materia Creation ----" << std::endl;
	IMateriaSource* src4 = new MateriaSource();
	src4->learnMateria(new Ice());
	ICharacter* me4 = new Character("me");
	AMateria* tmp4;
	tmp4 = src4->createMateria("fire");
	if (tmp4 == NULL)
		std::cout << "Invalid Materia type: fire" << std::endl;
	else
		me4->equip(tmp4);
	delete me4;
	delete src4;
	return 0;
}
