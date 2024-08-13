/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:59:57 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 14:59:59 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Default Destructor called" << std::endl;
}

void Cat::makeSound()
{
    std::cout << "Meaw" << std::endl;
}
