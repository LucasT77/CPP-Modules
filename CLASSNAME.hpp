#ifndef CLASSNAME_HPP
# define CLASSNAME_HPP

#include <iostream>

class CLASSNAME
{
	private:
		

	public:
		CLASSNAME();
		CLASSNAME(CLASSNAME &original);
		CLASSNAME &operator=(const CLASSNAME &original);
		~CLASSNAME();
};

# endif
