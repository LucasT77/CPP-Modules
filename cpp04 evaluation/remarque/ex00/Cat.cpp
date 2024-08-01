#include "Cat.hpp"

Cat::Cat(void) {
	this->type = "Cat";
	std::cout << "A Cat object has been created\n";
}
Cat::Cat(Cat const& f) : Animal() {
	this->type = f.type;
	std::cout << "A Cat object has been created by copying\n";
}
Cat::~Cat(void) {
	std:: cout << "A Cat object has been destroyed\n";
}
Cat& Cat::operator=(Cat const& f) {
	this->type = f.type;
	return *this;
}

void Cat::makeSound(void) const{
	std::cout << "Meow!\n";
}

std::string Cat::getType() const {
	return this->type;
}