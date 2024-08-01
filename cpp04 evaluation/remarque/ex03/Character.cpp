#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(Character const& c) {
	this->_name = c._name;
	for (int i = 0; i < 4; i++) {
		if (c._inventory[i] != NULL) {
			this->_inventory[i] = c._inventory[i]->clone();
		}
		else {
			this->_inventory[i] = NULL;
		}
	}
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
		}
	}
}

Character& Character::operator=(Character const& c) {
	if (this == &c)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		if (c._inventory[i] != NULL) {
			this->_inventory[i] = c._inventory[i]->clone();
		}
	}
	this->_name = c._name;
	return *this;
}

std::string const& Character::getName(void) const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
		return;
	this->_inventory[idx]->use(target);
}