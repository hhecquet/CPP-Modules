/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:23:43 by marvin            #+#    #+#             */
/*   Updated: 2025/05/21 08:23:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    //Search from the beginning to the end of this container for value, and give me an iterator to the first match.
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}

// Different containers have different iterator types:
// std::vector<T> → dynamic array (like a resizable C array)
// std::list<T> → doubly linked list
// std::array<T, N> → fixed-size array
// std::map<Key, Value> → key-value pairs (like a dictionary)
// std::set<T> → sorted unique values