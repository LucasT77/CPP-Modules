#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = "food";
	}
	std::cout << "A Brain object has been created\n";
}

Brain::Brain(Brain const& b) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = b.ideas[i];
	}
	std::cout << "A Brain object has been created by copying\n";
}
Brain::~Brain(void) {
	std:: cout << "A Brain object has been destroyed\n";
}
Brain& Brain::operator=(Brain const& b) {
	if (this == &b)
		return *this;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = b.ideas[i];
	}
	return *this;
}