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


ClapTrap::ClapTrap() {}
ClapTrap::ClapTrap(std::string name)
{
	Name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "ClapTrap default constructor called\n";
}
ClapTrap::ClapTrap(ClapTrap &copy)
{
	Name = copy.Name;
	hit_points = copy.hit_points;
	energy_points = copy.energy_points;
	attack_damage = copy.attack_damage;
	std::cout << "Copy constructor called\n";
}
ClapTrap &ClapTrap::operator=(const ClapTrap &clap_trap)
{
	this->Name = clap_trap.Name;
	this->hit_points = clap_trap.hit_points;
	this->energy_points = clap_trap.energy_points;
	this->attack_damage = clap_trap.attack_damage;
	std::cout << "Copy assignment operator calle\n";
	return (*this);
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called\n";
}


void    ClapTrap::attack(const std::string& target)
{
	if (energy_points == 0)
	{
		std::cout << Name << " has no energy left. Attack canceled!" << std::endl;
		return ;
	}
	energy_points--;
	std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << "*attack damage*" << " points of damage!" << std::endl;
	std::cout << Name << " has  " << energy_points << " Energy Points left." << std::endl;
}
void    ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points == 0)
	{
		std::cout << Name << " is already dead. You can stop attacking now!" << std::endl;
		return ;
	}
	hit_points -= amount;
	if (hit_points < 0)
		hit_points = 0;
	std::cout << Name << " has lost " << amount << " Hit Points." << std::endl;
	std::cout << Name << " has  " << hit_points << " Hit Points left" << std::endl;
	if (hit_points == 0)
		std::cout << Name << " died!" << std::endl;
}
void    ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points == 0)
	{
		std::cout << Name << " has no energy left. Repair canceled!" << std::endl;
		return ;
	}
	energy_points--;
	hit_points += amount;
	std::cout << Name << " has recovered " << amount << " Hit Points" << std::endl;
	std::cout << Name << " has  " << hit_points << " Hit Points left" << std::endl;
	std::cout << Name << " has  " << energy_points << " Energy Points left." << std::endl;
}
