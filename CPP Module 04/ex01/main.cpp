/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:58:11 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 15:02:12 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n\n/////////////////////////EX00/////////////////////////\n" << std::endl;

	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	c->makeSound(); //will output the cat sound!
	d->makeSound(); //will output the dog sound!
	meta->makeSound(); //will output the animal sound!
	
	std::cout << '\n';

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	std::cout << wc->getType() << " " << std::endl;
	wc->makeSound(); //will output the WrongCat sound!
	meta2->makeSound(); //will output the wrongAnimal sound!

	std::cout << '\n';

	delete meta;
	delete d;
	delete c;
	delete wc;
	delete meta2;
	
	std::cout << "\n\n/////////////////////////EX01/////////////////////////\n" << std::endl;

	int size = 6;
	int i = -1;
	Animal **animals = new Animal*[size];
	while (++i < size)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << "Type: "<< animals[i]->getType() << " " << std::endl;
		animals[i]->makeSound();
		std::cout << '\n';
	}
	i = -1;
	while (++i < size)
	{
		delete animals[i];
		std::cout << '\n';
	}
	delete [] animals;

	std::cout << "------------------" << std::endl;

	Dog basic;
	std::cout << "--------!!----------" << std::endl;
	{
		Dog tmp = basic;
	}
	std::cout << "--------**----------" << std::endl;

	return 0;
}
