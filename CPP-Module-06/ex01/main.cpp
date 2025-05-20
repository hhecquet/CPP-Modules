/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:17:03 by marvin            #+#    #+#             */
/*   Updated: 2025/05/20 10:17:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Serializer::Data data;
    data.i = 42;
    data.f = 3.14f;
    data.d = 2.718281828459045;
    data.c = 'H';

    std::cout << "Original Data: " << data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data: " << raw << std::endl;

    Serializer::Data *deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data: " << *deserializedData << std::endl;

    return 0;
}