/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:18:06 by marvin            #+#    #+#             */
/*   Updated: 2025/05/20 11:18:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
    private:
        T* _elements;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        
        unsigned int size() const;
        
        class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
};

#include "Array.tpp"