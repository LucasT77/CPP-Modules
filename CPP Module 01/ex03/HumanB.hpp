/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:29:27 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:29:29 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
    private:
	Weapon		_weapon;
	std::string	_name;

	public:
    void		setWeapon(Weapon weapon);
	void	    attack(void);
    HumanB(std::string name);
    ~HumanB(void);
};
