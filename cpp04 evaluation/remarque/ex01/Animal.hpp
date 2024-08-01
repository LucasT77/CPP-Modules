#pragma once
#include <string>
#include <iostream>

class Animal {
	protected:
	std::string type;
	public:
	Animal(void);
	Animal(Animal const&);
	virtual ~Animal(void);
	Animal& operator=(Animal const&);

	virtual void makeSound(void) const;
	virtual std::string getType(void) const;
};