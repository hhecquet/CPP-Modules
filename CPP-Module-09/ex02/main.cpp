/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:11:47 by hhecquet          #+#    #+#             */
/*   Updated: 2025/05/29 10:19:34 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    try {
        if (argc < 2)
            throw std::runtime_error("Error");

        std::vector<int> input = PmergeMe::parseArguments(argc, argv);

        PmergeMe::sortAndMeasure(input);

        std::deque<int> inputDeque(input.begin(), input.end());
        PmergeMe::sortAndMeasure(inputDeque);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}