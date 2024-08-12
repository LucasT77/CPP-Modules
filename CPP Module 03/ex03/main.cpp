/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:45:45 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/09 16:45:49 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap Z("Zeta");

	Z.attack("Itself");
	std::cout << std::endl;
	Z.takeDamage(20);
	std::cout << std::endl;
	Z.beRepaired(20);
	std::cout << std::endl;
	Z.whoAmI();
}
