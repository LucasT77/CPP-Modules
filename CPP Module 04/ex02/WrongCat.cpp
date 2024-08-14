/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:59:35 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 14:59:38 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &original)
{
    this->type = original.type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &original)
{
    this->type = original.type;
    std::cout << " WrongCat copy assignment constructor called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Default Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meaw" << std::endl;
}
