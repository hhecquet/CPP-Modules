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

int main(void)
{
    std::cout << "\n-----Aline's incrementation------\n" << std::endl;
	try
    {
		Bureaucrat b1("Aline", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;

		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
    catch (std::exception &e)
    {
		std::cerr << e.what() << std::endl;
	}
    std::cout << "\n-Corentin's wrong initialization-\n" << std::endl;
	try
    {
		Bureaucrat b2("Corentin", 151);
	}
    catch (std::exception &e)
    {
		std::cerr << e.what() << std::endl;
	}
    std::cout << "\n-----Collin's decrementation-----\n" << std::endl;
	try 
    {
		Bureaucrat b3("Collin", 149);
		std::cout << b3 << std::endl;
		b3.decrementGrade();
		std::cout << b3 << std::endl;
		b3.decrementGrade();
	}
    catch (std::exception &e)
    {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}