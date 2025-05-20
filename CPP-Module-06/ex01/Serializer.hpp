/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:09:53 by marvin            #+#    #+#             */
/*   Updated: 2025/05/20 10:09:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

class Serializer
{
    private :
        Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
        ~Serializer();

    public:
        struct Data
        {
            int i;
            float f;
            double d;
            char c;
        };

        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &out, const Serializer::Data &data);
