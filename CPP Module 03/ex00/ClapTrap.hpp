/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:06:31 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/09 18:06:32 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
	std::string Name;
	int         hit_points;
	int         energy_points;
	int         attack_damage;
	
	public:
	ClapTrap(std::string name);
	~ClapTrap();
	void    attack(const std::string& target);
	void    takeDamage(unsigned int amount);
	void    beRepaired(unsigned int amount);
};

#endif
