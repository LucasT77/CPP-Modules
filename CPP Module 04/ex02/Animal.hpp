/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:58:25 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 14:58:27 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(Animal &original);
		Animal &operator=(const Animal &original);
		virtual ~Animal();
		virtual void makeSound() const = 0;
		std::string getType() const;
};

# endif
