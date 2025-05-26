/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:05:56 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 10:04:49 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
	Bureaucrat bob("Bob", 1);
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
	bob.signForm(*form);
	bob.executeForm(*form);
	std::cout << std::endl;
    if (form)
        delete form;
    form = someRandomIntern.makeForm("unknown form", "Bender");
    if (form)
        delete form;

    return 0;
}