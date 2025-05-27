/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:20:19 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 08:41:38 by hhecquet         ###   ########.fr       */
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
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
    
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        unsigned int count = std::distance(begin, end);
        if (_numbers.size() + count > _maxSize) {
            throw std::out_of_range("Cannot add range: would exceed maximum capacity");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    class FullSpanException : public std::exception {
    public:
        const char *what() const throw();
    };

    class NotEnoughNumbersException : public std::exception {
    public:
        const char *what() const throw();
    };
};