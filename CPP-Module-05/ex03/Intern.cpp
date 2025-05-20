/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:05:32 by marvin            #+#    #+#             */
/*   Updated: 2025/05/19 10:05:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &) {}

Intern &Intern::operator=(const Intern &) {
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    int formIndex = -1;

    for (int i = 0; i < 3; ++i) {
        if (formName == names[i]) {
            formIndex = i;
            break;
        }
    }
    
    switch (formIndex) {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return createShrubbery(target);
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return createRobotomy(target);
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return createPresidential(target);
        default:
            break;
    }

    std::cout << "Error: Intern cannot create form \"" << formName << "\" because it does not exist." << std::endl;
    return NULL;
}

AForm* Intern::createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}