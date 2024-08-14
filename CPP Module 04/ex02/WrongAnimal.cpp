/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:58:54 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 14:58:59 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &original)
{
    this->type = original.type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &original)
{
    this->type = original.type;
    std::cout << " WrongAnimal copy assignment constructor called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Default Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "*Some WrongAnimal Sound*" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}
