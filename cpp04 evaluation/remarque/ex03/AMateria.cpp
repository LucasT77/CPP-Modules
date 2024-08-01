#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) {}

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::~AMateria(void) {}

AMateria& AMateria::operator=(AMateria const& a) {
	this->_type = a._type;
	return *this;
}

std::string const& AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "Materia has been used\n";
}