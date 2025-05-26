/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:20:19 by marvin            #+#    #+#             */
/*   Updated: 2025/05/21 09:20:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Constructors, destructor, and assignment operator
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    // Member functions
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
    
    // Function to add numbers using a range of iterators
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        unsigned int count = std::distance(begin, end);
        if (_numbers.size() + count > _maxSize) {
            throw std::out_of_range("Cannot add range: would exceed maximum capacity");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    // Exception classes
    class FullSpanException : public std::exception {
    public:
        const char *what() const throw();
    };

    class NotEnoughNumbersException : public std::exception {
    public:
        const char *what() const throw();
    };
};