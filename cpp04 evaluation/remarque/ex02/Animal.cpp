#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "An Animal object has been created\n";
}
Animal::Animal(Animal const& f) : type(f.type) {
	std::cout << "An Animal object has been created by copying\n";
}
Animal::~Animal(void) {
	std:: cout << "An Animal object has been destroyed\n";
}
Animal& Animal::operator=(Animal const& f) {
	std:: cout << "An Animal object has assigned\n";
	this->type = f.type;
	return *this;
}

void Animal::makeSound(void) const{
	std::cout << "An animal made a sound.\n";
}

std::string Animal::getType() const {
	return "animal";
}