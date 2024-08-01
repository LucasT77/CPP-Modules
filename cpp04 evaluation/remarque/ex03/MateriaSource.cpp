#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		this->sources[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const& m) {
	for (int i = 0; i < 4; i++) {
		if (m.sources[i] != NULL) {
			this->sources[i] = m.sources[i]->clone();
		}
		else {
			this->sources[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (this->sources[i] != NULL) {
			delete this->sources[i];
		}
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const& m) {
	if (this == &m)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (this->sources[i] != NULL) {
			delete this->sources[i];
			this->sources[i] = NULL;
		}
		if (m.sources[i] != NULL) {
			this->sources[i] = m.sources[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++) {
		if (this->sources[i] == NULL) {
			this->sources[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (this->sources[i] != NULL && this->sources[i]->getType() == type) {
			return this->sources[i]->clone();
		}
	}
	return NULL;
}