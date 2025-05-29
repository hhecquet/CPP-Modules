/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:31:50 by hhecquet          #+#    #+#             */
/*   Updated: 2025/05/29 10:21:01 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> PmergeMe::parseArguments(int argc, char** argv) {
    std::vector<int> result;
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        for (size_t j = 0; j < arg.size(); ++j) {
            if (!isdigit(arg[j]))
                throw std::runtime_error("Error");
        }
        long num = std::strtol(arg.c_str(), NULL, 10);
        if (num < 0 || num > INT_MAX)
            throw std::runtime_error("Error");
        result.push_back(static_cast<int>(num));
    }
    return result;
}

void PmergeMe::sortAndMeasure(std::vector<int> input) {
    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); ++i)
        std::cout << input[i] << " ";
    std::cout << std::endl;

    std::clock_t start = std::clock();
    mergeInsertSort(input);
    std::clock_t end = std::clock();

    std::cout << "After: ";
    for (size_t i = 0; i < input.size(); ++i)
        std::cout << input[i] << " ";
    std::cout << std::endl;

    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << input.size()
              << " elements with std::vector : " << duration << " us" << std::endl;
}

void PmergeMe::sortAndMeasure(std::deque<int> input) {
    std::clock_t start = std::clock();
    mergeInsertSort(input);
    std::clock_t end = std::clock();

    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << input.size()
              << " elements with std::deque  : " << duration << " us" << std::endl;
}

void PmergeMe::mergeInsertSort(std::vector<int>& data) {
    mergeInsertSortImpl(data, 0, data.size());
}

void PmergeMe::mergeInsertSort(std::deque<int>& data) {
    mergeInsertSortImpl(data, 0, data.size());
}

void PmergeMe::mergeInsertSortImpl(std::vector<int>& data, size_t left, size_t right) {
    if (right - left <= 1)
        return;
    size_t mid = (left + right) / 2;
    mergeInsertSortImpl(data, left, mid);
    mergeInsertSortImpl(data, mid, right);
    merge(data, left, mid, right);
}

void PmergeMe::mergeInsertSortImpl(std::deque<int>& data, size_t left, size_t right) {
    if (right - left <= 1)
        return;
    size_t mid = (left + right) / 2;
    mergeInsertSortImpl(data, left, mid);
    mergeInsertSortImpl(data, mid, right);
    merge(data, left, mid, right);
}

void PmergeMe::merge(std::vector<int>& data, size_t left, size_t mid, size_t right) {
    std::vector<int> temp;
    size_t i = left, j = mid;
    while (i < mid && j < right) {
        if (data[i] < data[j])
            temp.push_back(data[i++]);
        else
            temp.push_back(data[j++]);
    }
    while (i < mid)
        temp.push_back(data[i++]);
    while (j < right)
        temp.push_back(data[j++]);

    for (size_t k = 0; k < temp.size(); ++k)
        data[left + k] = temp[k];
}

void PmergeMe::merge(std::deque<int>& data, size_t left, size_t mid, size_t right) {
    std::deque<int> temp;
    size_t i = left, j = mid;
    while (i < mid && j < right) {
        if (data[i] < data[j])
            temp.push_back(data[i++]);
        else
            temp.push_back(data[j++]);
    }
    while (i < mid)
        temp.push_back(data[i++]);
    while (j < right)
        temp.push_back(data[j++]);

    for (size_t k = 0; k < temp.size(); ++k)
        data[left + k] = temp[k];
}