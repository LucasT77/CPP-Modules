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
    brain = new Brain();
    std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(Cat &original) 
{
    this->type = original.type;
    this->brain = new Brain();
    *brain = *(original.brain);
    std::cout << " Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &original)
{
    this->type = original.type;
    this->brain = new Brain();
    *brain = *(original.brain);
    std::cout << " Cat copy assignment constructor called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Default Destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Meaw" << std::endl;
}
