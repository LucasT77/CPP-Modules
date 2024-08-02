/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:28:49 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:28:51 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	Weapon::getType(void)
{
	return (_type);
}

void	Weapon::setType(std::string newType)
{
	_type += newType;
}

Weapon::Weapon(std::string type)
{

}

Weapon::~Weapon(void)
{

}
