/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:19:43 by marvin            #+#    #+#             */
/*   Updated: 2025/05/16 14:19:43 by marvin           ###   ########.fr       */
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

		sam.signForm(robot);
		sam.executeForm(robot);
		bob.executeForm(robot);

		bob.signForm(pardon);
		bob.executeForm(pardon);

		ShrubberyCreationForm testFail("park");
		bob.executeForm(testFail);

	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
