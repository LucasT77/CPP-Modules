/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:51:03 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/14 14:51:05 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(Brain &original)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = original.ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &original)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = original.ideas[i];
    std::cout << " Brain copy assignment constructor called" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Default Destructor called" << std::endl;
}
