#include "Animal.hpp"
#pragma once

class Cat : public Animal {
	public:
	Cat(void);
	Cat(Cat const&);
	~Cat(void);
	Cat& operator=(Cat const&);

	void makeSound(void) const;
	std::string getType() const;
};