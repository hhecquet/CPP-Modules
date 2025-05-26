/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:20:27 by marvin            #+#    #+#             */
/*   Updated: 2025/05/21 09:20:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
Span::Span() : _maxSize(0) {}

// Parameterized constructor
Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N);  // Pre-allocate memory for efficiency
}

// Copy constructor
Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

// Assignment operator
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

// Destructor
Span::~Span() {}

// Add a single number to the span
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw FullSpanException();
    }
    _numbers.push_back(number);
}

// Find the shortest span between any two numbers
int Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw NotEnoughNumbersException();
    }

    // Create a sorted copy of the numbers
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    // Find the minimum difference between adjacent elements
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        minSpan = std::min(minSpan, span);
    }

    return minSpan;
}

// Find the longest span between any two numbers
int Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw NotEnoughNumbersException();
    }

    // Find min and max elements
    std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> minmax = 
        std::minmax_element(_numbers.begin(), _numbers.end());
    
    // Calculate the difference between max and min
    return *minmax.second - *minmax.first;
}

// Exception messages
const char *Span::FullSpanException::what() const throw() {
    return "Cannot add number: Span is already full";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
    return "Cannot find span: Need at least two numbers";
}