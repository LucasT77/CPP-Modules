/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:28:40 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:28:41 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
	std::string	_type;

	public:
	Weapon(std::string type);
	~Weapon(void);
	const std::string	getType(void);
	void				setType(std::string newType);
};

#endif
