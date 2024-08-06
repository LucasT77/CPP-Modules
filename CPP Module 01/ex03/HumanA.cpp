/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:29:13 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:29:14 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void    HumanA::attack(void)
{
    std::cout << _name << " attacks with their " << _weapon.getType() << '\n';
}

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{

}

HumanA::~HumanA(void)
{

}

void	HumanA::setWeapon(Weapon weapon)
{
    _weapon = weapon;
}
