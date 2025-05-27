/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:20:27 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 09:03:09 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N);  // Pre-allocate memory for efficiency ¯\_(ツ)_/¯
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw FullSpanException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw NotEnoughNumbersException();
    }

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        minSpan = std::min(minSpan, span);
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw NotEnoughNumbersException();
    }

    std::vector<int>::const_iterator minIt =
        std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt =
        std::max_element(_numbers.begin(), _numbers.end());
    return  *maxIt - *minIt;
}

const char *Span::FullSpanException::what() const throw() {
    return "Cannot add number: Span is already full";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
    return "Cannot find span: Need at least two numbers";
}