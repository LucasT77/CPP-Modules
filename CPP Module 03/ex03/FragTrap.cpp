/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:48:02 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/09 16:48:03 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap() {}
FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "FragTrap default constructor called\n";
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called\n";
}


void FragTrap::attack(const std::string& target)
{
	if (energy_points == 0)
	{
		std::cout << Name << " has no energy left. Attack canceled!" << std::endl;
		return ;
	}
	energy_points--;
	std::cout << "FragTrap " << Name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	std::cout << Name << " has  " << energy_points << " Energy Points left." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Hey, gime a High Five! 🖐️" << std::endl;
}
