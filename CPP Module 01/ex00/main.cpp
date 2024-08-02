/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:24:07 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:24:11 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie		*newZombie(std::string name);

void		randomChump(std::string name);

int main(void)
{
    Zombie *z1 = newZombie("Zombozo");
    z1->announce();
    randomChump("Zombismu");
    delete(z1);
}
