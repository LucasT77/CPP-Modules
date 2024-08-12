/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:18:17 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/12 17:18:19 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ScavTrap(), FragTrap() {}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    Name = name;
    ClapTrap::Name = name + "_clap_name";
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(DiamondTrap &original)
{
	*this = original;
	std::cout << "DiamondTrap Copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
	this->Name = original.Name;
	ClapTrap::Name = this->Name + "_clap_name";
	this->hit_points = original.hit_points;
	this->energy_points = original.energy_points;
	this->attack_damage = original.attack_damage;
	std::cout << "DiamondTrap Copy assignment operator calle\n";
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout   << "My name: " << Name << std::endl
                << "My ClapTrap name: " << ClapTrap::Name << std::endl;
}
