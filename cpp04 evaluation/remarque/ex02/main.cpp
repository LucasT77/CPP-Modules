#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	std::cout << "--- PDF Tests ---\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "---\n";
	delete j;//should not create a leak
	delete i;
	std::cout << "--- Create Array ---\n";
	Animal* array[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			array[i] = new Dog();
		}
		else {
			array[i] = new Cat();
		}
	}
	std::cout << "--- Delete Array ---\n";
	for (int i = 0; i < 10; i++) {
		delete array[i];
	}
	std::cout << "--- Execute tmp dog ---\n";
	Dog basic;
	{
		Dog tmp = basic;
	}
	std::cout << "--- tmp dog executed ---\n";
	// if the next line is uncommented, code shouldn't compile	
	//Animal test;
}