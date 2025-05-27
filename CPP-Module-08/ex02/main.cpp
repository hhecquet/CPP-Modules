/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:20:31 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 09:24:00 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"
#include <list>

void testWithMutantStack() {
    std::cout << "-- MutantStack Test --\n";
    MutantStack<int> m;
    for (int i = 1; i <= 5; ++i)
        m.push(i * 10);

    std::cout << "Top: " << m.top() << " (expect 50)\n";
    m.pop();
    std::cout << "Size after pop: " << m.size() << " (expect 4)\n";

	m.push(50);
    std::cout << "Elements: ";
    for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
        std::cout << *it << ' ';
    std::cout << "\n";

    const MutantStack<int>& cm = m;
    std::cout << "Const-iter elements: ";
    for (MutantStack<int>::const_iterator it = cm.begin(); it != cm.end(); ++it)
        std::cout << *it << ' ';
    std::cout << "\n";

    std::cout << "Reverse: ";
    for (MutantStack<int>::reverse_iterator rit = m.rbegin(); rit != m.rend(); ++rit)
        std::cout << *rit << ' ';
    std::cout << "\n";

    MutantStack<int> copy = m;
    std::cout << "Copy front element: " << *copy.begin() << " (expect 10)\n";

    std::stack<int> s(m);
    std::cout << "STD stack top from copy: " << s.top() << " (expect 40)\n";
}

void testWithList() {
    std::cout << "-- std::list Test (same output) --\n";
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i)
        lst.push_back(i * 10);

    std::cout << "Elements: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << ' ';
    std::cout << "\n";
}

int main() {
    testWithMutantStack();
    testWithList();
    return 0;
}


// int main()
// {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);

//     std::cout << mstack.top() << std::endl;

//     mstack.pop();

//     std::cout << mstack.size() << std::endl;

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }