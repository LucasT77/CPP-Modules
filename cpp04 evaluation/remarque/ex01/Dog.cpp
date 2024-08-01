#include "Dog.hpp"

Dog::Dog(void) {
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "A Dog object has been created\n";
}
Dog::Dog(Dog const& f) : Animal() {
	this->brain = new Brain(*f.brain);
	this->type = f.type;
	std::cout << "A Dog object has been created by copying\n";
}
Dog::~Dog(void) {
	delete this->brain;
	std:: cout << "A Dog object has been destroyed\n";
}
Dog& Dog::operator=(Dog const& d) {
	if (this == &d)
		return *this;
	this->brain = new Brain(*d.brain);
	this->type = d.type;
	return *this;
}

void Dog::makeSound(void) const{
	std::cout << "Woof!\n";
}

std::string Dog::getType() const {
	return this->type;
}