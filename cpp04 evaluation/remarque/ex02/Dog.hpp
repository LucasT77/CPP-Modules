#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
	Brain* brain;
	public:
	Dog(void);
	Dog(Dog const&);
	~Dog(void);
	Dog& operator=(Dog const&);

	void makeSound(void) const;
	std::string getType() const;
};