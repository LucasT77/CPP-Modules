/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:29:45 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:29:46 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
	
void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << '\n';
	else
		std::cout << _name << " attacks without a weapon" << std::endl;
}

HumanB::HumanB(std::string name): _weapon(NULL)
{
	_name = name;
}

HumanB::~HumanB(void)
{
	
}
