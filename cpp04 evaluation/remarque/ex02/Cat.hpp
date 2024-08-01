#include "Animal.hpp"
#include "Brain.hpp"
#pragma once

class Cat : public Animal {
	private:
	Brain* brain;
	public:
	Cat(void);
	Cat(Cat const&);
	~Cat(void);
	Cat& operator=(Cat const&);

	void makeSound(void) const;
	std::string getType() const;
};