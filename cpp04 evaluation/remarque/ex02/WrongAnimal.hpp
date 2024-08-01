#pragma once
#include <string>
#include <iostream>

class WrongAnimal {
	protected:
	std::string type;
	public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const&);
	virtual ~WrongAnimal(void);
	WrongAnimal& operator=(WrongAnimal const&);

	void makeSound(void) const;
	virtual std::string getType(void) const;
};