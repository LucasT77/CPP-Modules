/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:47:31 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/09 16:47:33 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap() {}
ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap default constructor called\n";
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
	if (energy_points == 0)
	{
		std::cout << Name << " has no energy left. Attack canceled!" << std::endl;
		return ;
	}
	energy_points--;
	std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	std::cout << Name << " has  " << energy_points << " Energy Points left." << std::endl;
}
