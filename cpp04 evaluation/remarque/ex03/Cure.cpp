#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(Cure const& i) : AMateria("cure") {
	*this = i;
}

Cure::~Cure(void) {}

AMateria* Cure::clone(void) const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}