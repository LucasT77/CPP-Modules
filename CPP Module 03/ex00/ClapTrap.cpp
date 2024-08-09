/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:16:45 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/09 18:17:08 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    Name = name;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
}
ClapTrap::~ClapTrap() {}


void    ClapTrap::attack(const std::string& target)
{
    if (energy_points == 0)
    {
        std::cout << "ClapTrap has no energy left. Attack canceled" << std::endl;
        return ;
    }
    energy_points--;
    
}
void    ClapTrap::takeDamage(unsigned int amount)
{

}
void    ClapTrap::beRepaired(unsigned int amount)
{

}
