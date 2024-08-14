/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:58:31 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 14:58:33 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(Animal &original)
{
    this->type = original.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &original)
{
    this->type = original.type;
    std::cout << " Animal copy assignment constructor called" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Default Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "*Some Animal Sound*" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}
