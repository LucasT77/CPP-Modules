#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
	AMateria* sources[4];

	public:
	MateriaSource(void);
	MateriaSource(MateriaSource const& m);

	~MateriaSource(void);

	MateriaSource& operator=(MateriaSource const& m);

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const& type);
};