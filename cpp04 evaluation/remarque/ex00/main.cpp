#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " \n";
	std::cout << i->getType() << " \n";
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << "---\n";
	Animal animal = Animal();
	animal.makeSound();
	Dog dog = Dog();
	dog.makeSound();
	Cat cat = Cat();
	cat.makeSound();
	Animal zelda = Dog();
	zelda.makeSound();
	std::cout << "---\n";
	const WrongAnimal* wrong = new WrongCat();
	wrong->makeSound();
	delete wrong;
	std::cout << "---\n";
}