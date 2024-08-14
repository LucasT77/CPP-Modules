/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:00:29 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 15:00:31 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(Dog &original) 
{
    this->type = original.type;
    this->brain = new Brain();
    *brain = *(original.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &original)
{
    this->type = original.type;
    this->brain = new Brain();
    *brain = *(original.brain);
    std::cout << " Dog copy assignment constructor called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Default Destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}
