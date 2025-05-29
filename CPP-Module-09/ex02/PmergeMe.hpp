/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:31:54 by hhecquet          #+#    #+#             */
/*   Updated: 2025/05/29 10:21:13 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <climits>

class PmergeMe {
public:
    static void sortAndMeasure(std::vector<int> input);
    static void sortAndMeasure(std::deque<int> input);

    static std::vector<int> parseArguments(int argc, char** argv);
private:
    // Ford-Johnson implementation for vector
    static void mergeInsertSort(std::vector<int>& data);
    // Ford-Johnson implementation for deque
    static void mergeInsertSort(std::deque<int>& data);

	static void mergeInsertSortImpl(std::vector<int>& data, size_t left, size_t right);
    static void mergeInsertSortImpl(std::deque<int>& data, size_t left, size_t right);

    static void merge(std::vector<int>& data, size_t left, size_t mid, size_t right);
    static void merge(std::deque<int>& data, size_t left, size_t mid, size_t right);
};