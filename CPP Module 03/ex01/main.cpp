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

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap LukeSkywalker("Luke Skywalker");
	ScavTrap DarthVader("Darth Vader");

	LukeSkywalker.attack("Darth Vader");
	DarthVader.takeDamage(20);
	std::cout << std::endl;
	LukeSkywalker.attack("Darth Vader");
	DarthVader.takeDamage(20);
	std::cout << std::endl;
	DarthVader.attack("Luke Skywalker");
	LukeSkywalker.takeDamage(20);
	std::cout << std::endl;
	LukeSkywalker.beRepaired(20);
	std::cout << std::endl;
	LukeSkywalker.attack("Darth Vader");
	DarthVader.takeDamage(20);
	std::cout << std::endl;
	DarthVader.beRepaired(20);
	std::cout << std::endl;
	DarthVader.attack("Luke Skywalker");
	LukeSkywalker.takeDamage(20);
	std::cout << std::endl;
	LukeSkywalker.attack("Darth Vader");
	DarthVader.takeDamage(20);
	std::cout << std::endl;
	DarthVader.attack("Luke Skywalker");
	LukeSkywalker.takeDamage(20);
	std::cout << std::endl;
	LukeSkywalker.beRepaired(20);
	DarthVader.beRepaired(20);
	LukeSkywalker.beRepaired(20);
	DarthVader.beRepaired(20);
	LukeSkywalker.beRepaired(20);
	DarthVader.beRepaired(20);
	LukeSkywalker.beRepaired(20);
	DarthVader.beRepaired(20);
	std::cout << std::endl;
	LukeSkywalker.attack("Darth Vader");
	DarthVader.attack("Luke Skywalker");
	DarthVader.takeDamage(20);
	LukeSkywalker.takeDamage(20);
	std::cout << std::endl;
	LukeSkywalker.attack("Darth Vader");
	DarthVader.attack("Luke Skywalker");
	LukeSkywalker.takeDamage(20);
	std::cout << std::endl;
	DarthVader.attack("Luke Skywalker");
	std::cout << std::endl;
	LukeSkywalker.guardGate();
	DarthVader.guardGate();
}
