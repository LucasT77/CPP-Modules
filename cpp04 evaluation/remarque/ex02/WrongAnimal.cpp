#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "An WrongAnimal object has been created\n";
}
WrongAnimal::WrongAnimal(WrongAnimal const& f) : type(f.type) {
	std::cout << "An WrongAnimal object has been created by copying\n";
}
WrongAnimal::~WrongAnimal(void) {
	std:: cout << "An WrongAnimal object has been destroyed\n";
}
WrongAnimal& WrongAnimal::operator=(WrongAnimal const& f) {
	std:: cout << "An WrongAnimal object has assigned\n";
	this->type = f.type;
	return *this;
}

void WrongAnimal::makeSound(void) const{
	std::cout << "An animal made a sound.\n";
}

std::string WrongAnimal::getType() const {
	return "animal";
}