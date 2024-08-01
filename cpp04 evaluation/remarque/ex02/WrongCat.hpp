#include "WrongAnimal.hpp"
#pragma once

class WrongCat : public WrongAnimal {
	public:
	WrongCat(void);
	WrongCat(WrongCat const&);
	~WrongCat(void);
	WrongCat& operator=(WrongCat const&);

	void makeSound(void) const;
	std::string getType() const;
};