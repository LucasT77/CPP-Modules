/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:18:55 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/30 18:18:58 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

///////Constructors & Destructor

Serializer::Serializer() {}
Serializer::Serializer(Serializer &other) {(void)other;}
Serializer &Serializer::operator=(const Serializer &other) 
{
	(void)other;
	return *this;
}
Serializer::~Serializer() {}

///////Methods

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
