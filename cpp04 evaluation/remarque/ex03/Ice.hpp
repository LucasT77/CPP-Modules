#pragma once
#include "AMateria.hpp"

class Ice : public AMateria {
	public:
	Ice(void);
	Ice(Ice const& i);

	~Ice(void);

	AMateria* clone() const;
	void use(ICharacter& target);
};