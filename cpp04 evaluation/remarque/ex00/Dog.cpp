#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog(void) {
	this->type = "Dog";
	std::cout << "A Dog object has been created\n";
}
Dog::Dog(Dog const& f) : Animal() {
	this->type = f.type;
	std::cout << "AnDog object has been created by copying\n";
}
Dog::~Dog(void) {
	std:: cout << "A Dog object has been destroyed\n";
}
Dog& Dog::operator=(Dog const& f) {
	this->type = f.type;
	return *this;
}

void Dog::makeSound(void) const{
	std::cout << "Woof!\n";
}

std::string Dog::getType() const {
	return this->type;
}