/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:24:49 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:24:50 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
	std::string _name;

	public:
	void		announce(void);
	Zombie(std::string name);
    Zombie(void);
	~Zombie(void);
    void    setName(std::string name);
};

#endif
