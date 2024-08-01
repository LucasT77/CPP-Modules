#pragma once
#include "Animal.hpp"

class Dog : public Animal {
	public:
	Dog(void);
	Dog(Dog const&);
	~Dog(void);
	Dog& operator=(Dog const&);

	void makeSound(void) const;
	std::string getType() const;
};