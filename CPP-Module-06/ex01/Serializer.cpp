/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:09:50 by marvin            #+#    #+#             */
/*   Updated: 2025/05/20 10:09:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &other){(void)other;}

Serializer &Serializer::operator=(const Serializer &other){
    (void)other;
    return *this;
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Serializer::Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Serializer::Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Serializer::Data *>(raw);
}

std::ostream &operator<<(std::ostream &out, const Serializer::Data &data)
{
    out << "{ i: " << data.i << ", f: " << data.f << ", d: " << data.d << ", c: '" << data.c << "' }";
    return out;
}