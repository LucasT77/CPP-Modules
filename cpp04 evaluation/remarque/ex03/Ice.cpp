#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(Ice const& i) : AMateria("ice") {
	*this = i;
}

Ice::~Ice(void) {}

AMateria* Ice::clone(void) const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots ice bolt at " << target.getName() << " *\n";
}