#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	this->type = "WrongCat";
	std::cout << "A WrongCat object has been created\n";
}
WrongCat::WrongCat(WrongCat const& f) : WrongAnimal() {
	this->type = f.type;
	std::cout << "A WrongCat object has been created by copying\n";
}
WrongCat::~WrongCat(void) {
	std:: cout << "A WrongCat object has been destroyed\n";
}
WrongCat& WrongCat::operator=(WrongCat const& f) {
	this->type = f.type;
	return *this;
}

void WrongCat::makeSound(void) const{
	std::cout << "Meow!\n";
}

std::string WrongCat::getType() const {
	return this->type;
}