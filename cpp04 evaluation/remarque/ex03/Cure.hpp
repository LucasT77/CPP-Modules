#pragma once
#include "AMateria.hpp"

class Cure : public AMateria {
	public:
	Cure(void);
	Cure(Cure const& i);

	~Cure(void);

	AMateria* clone() const;
	void use(ICharacter& target);
};