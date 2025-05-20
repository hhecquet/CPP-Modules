/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:15:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/19 10:15:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal) {
    double value = 0.0;
    bool isCharLiteral = (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');

    if (isCharLiteral) {
        char c = literal[1];
        value = static_cast<double>(c);
    } else if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff") {
        if (literal == "nan" || literal == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf" || literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
    } else {
        std::istringstream iss(literal);
        if (!(iss >> value)) {
            std::cout << "Invalid input" << std::endl;
            return;
        }
    }
    std::cout << "char: ";
    if (isnan(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<char>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    std::cout << "int: ";
    if (isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << value << std::endl;
}