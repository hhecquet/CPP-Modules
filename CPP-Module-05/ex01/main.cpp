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

#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b("Collin", 5);
        Form f("LeaveForm", 10, 3);

        std::cout << b << std::endl;
        std::cout << f << std::endl;

        b.signForm(f);
        std::cout << f << std::endl;

        Form f2("PermissionSlip", 6, 6);
        b.signForm(f2);
        std::cout << f2 << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---------------------------\n";

    try {
        Form badForm("IllegalForm", 0, 150);
    } catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form badForm2("AnotherBadForm", 151, 100);
    } catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n---------------------------\n";

    Bureaucrat a("Aline", 1);
    Bureaucrat z("Corentin", 150);
    Form topSecret("TopSecret", 1, 1);

    a.signForm(topSecret);
    z.signForm(topSecret);

    std::cout << topSecret << std::endl;

    return 0;
}
