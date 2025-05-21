/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:47:50 by marvin            #+#    #+#             */
/*   Updated: 2025/05/21 07:47:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void doubleValue(T& x) {
    x *= 2;
}

void incrementChar(char& x) {
    x += 1;
}

void appendString(std::string& x) {
    x += " modified";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
    for (size_t i = 0; i < intLength; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << "\nResult : ";
    iter(intArray, intLength, doubleValue<int>);
    for (size_t i = 0; i < intLength; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charLength = sizeof(charArray) / sizeof(charArray[0]);
    for (size_t i = 0; i < charLength; ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << "\nResult : ";
    iter(charArray, charLength, incrementChar);
    for (size_t i = 0; i < charLength; ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    std::string strArray[] = {"hello", "world", "!"};
    size_t strLength = sizeof(strArray) / sizeof(strArray[0]);
    for (size_t i = 0; i < strLength; ++i) {
        std::cout << strArray[i] << " ";
    }
    std::cout << "\nResult : ";
    iter(strArray, strLength, appendString);
    for (size_t i = 0; i < strLength; ++i) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}