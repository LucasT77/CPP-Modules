#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
	std::string _name;
	AMateria* _inventory[4];

	public:
	Character(std::string name);
	Character(Character const& c);

	~Character(void);

	Character& operator=(Character const& c);

	std::string const& getName(void) const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};