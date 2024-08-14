/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:00:03 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 15:00:05 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(Cat &original);
		Cat &operator=(const Cat &original);
		~Cat();
		void makeSound() const;
};

# endif
