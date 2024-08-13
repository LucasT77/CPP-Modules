/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:59:06 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 14:59:08 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	private:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal &original);
		WrongAnimal &operator=(const WrongAnimal &original);
		~WrongAnimal();
};

# endif
