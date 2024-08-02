/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:29:06 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:29:07 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	private:
	Weapon &_weapon;
	std::string	_name;

	public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void		attack(void);
	void		setWeapon(Weapon weapon);
};
