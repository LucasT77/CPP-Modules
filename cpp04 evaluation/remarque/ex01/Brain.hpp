#pragma once
#include <string>

class Brain {
	private:
	std::string ideas[100];
	public:
	Brain(void);
	Brain(Brain const&);
	~Brain(void);
	Brain& operator=(Brain const&);
};