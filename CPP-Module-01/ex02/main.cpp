/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:56:43 by hhecquet          #+#    #+#             */
/*   Updated: 2025/04/22 11:12:07 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "The memory address of the string variable :" << &str << std::endl;
	std::cout << "The memory address held by stringPTR :" << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF :" << &stringREF << std::endl;

	std::cout << "The value of the string variable :" << str << std::endl;
	std::cout << "The value pointed to by stringPTR :" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF :" << stringREF << std::endl;

	return (0);
}