/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:28:57 by marvin            #+#    #+#             */
/*   Updated: 2025/05/20 10:28:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

class Base
{
    public:
        virtual ~Base() {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);