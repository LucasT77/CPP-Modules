#include "Cat.hpp"

Cat::Cat(void) {
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "A Cat object has been created\n";
}
Cat::Cat(Cat const& c) : Animal() {
	this->brain = new Brain(*c.brain);
	this->type = c.type;
	std::cout << "A Cat object has been created by copying\n";
}
Cat::~Cat(void) {
	delete this->brain;
	std:: cout << "A Cat object has been destroyed\n";
}
Cat& Cat::operator=(Cat const& c) {
	if (this == &c)
		return *this;
	this->brain = new Brain(*c.brain);
	this->type = c.type;
	return *this;
}

void Cat::makeSound(void) const{
	std::cout << "Meow!\n";
}

std::string Cat::getType() const {
	return this->type;
}