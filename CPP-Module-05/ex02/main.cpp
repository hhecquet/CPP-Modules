/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:19:43 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 09:52:59 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat bob("Bob", 1);
		Bureaucrat jim("Jim", 140);
		Bureaucrat sam("Sam", 50);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Marvin");
		PresidentialPardonForm pardon("Ford");

		jim.signForm(shrub);
		jim.executeForm(shrub);
		bob.executeForm(shrub);
		std::cout << std::endl;
		sam.signForm(robot);
		sam.executeForm(robot);
		bob.executeForm(robot);
		std::cout << std::endl;
		bob.signForm(pardon);
		bob.executeForm(pardon);
		std::cout << std::endl;
		ShrubberyCreationForm testFail("park");
		bob.executeForm(testFail);

	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
