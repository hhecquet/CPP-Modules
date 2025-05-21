/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:23:24 by marvin            #+#    #+#             */
/*   Updated: 2025/05/21 08:23:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <iostream>

template <typename T>
void testEasyFind(T& container, int valueToFind, const std::string& containerType) {
    std::cout << "Testing " << containerType << ": ";
    try {
        typename T::iterator result = easyfind(container, valueToFind);
        std::cout << "Value " << valueToFind << " found at position: ";
        typename T::iterator it = container.begin();
        int position = 0;
        while (it != result) {
            ++it;
            ++position;
        }
        std::cout << position << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    // Test with std::vector
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i * 10);
    
    // Test with std::list
    std::list<int> lst;
    for (int i = 0; i < 10; i++)
        lst.push_back(i * 10);
    
    // Test with std::deque
    std::deque<int> deq;
    for (int i = 0; i < 10; i++)
        deq.push_back(i * 10);
    
    // Test with std::set
    std::set<int> st;
    for (int i = 0; i < 10; i++)
        st.insert(i * 10);
    
    std::cout << "=== SUCCESSFUL SEARCHES ===" << std::endl;
    testEasyFind(vec, 30, "std::vector");
    testEasyFind(lst, 50, "std::list");
    testEasyFind(deq, 70, "std::deque");
    testEasyFind(st, 90, "std::set");
    
    std::cout << "\n=== FAILED SEARCHES ===" << std::endl;
    testEasyFind(vec, 45, "std::vector");
    testEasyFind(lst, -10, "std::list");
    testEasyFind(deq, 100, "std::deque");
    testEasyFind(st, 55, "std::set");
    
    return 0;
}

//If you only need to add/remove at the end, use vector.
// If you need to add/remove from both ends, use deque.

//push_back() add at the end