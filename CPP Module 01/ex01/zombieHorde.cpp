/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:27:32 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:27:34 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*z;
	int 	i = -1;

	if (N < 0)
	{
		std::cout << "Invalid number of Zombies." << std::endl;
		return (NULL);
	}
	z = new Zombie[N];
	while (++i < N)
		z[i].setName(name);
	return (z);
}
