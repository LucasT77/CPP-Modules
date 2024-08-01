#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# pragma once
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
	std::string _type;

	public:
	AMateria(void);
	AMateria(std::string const& type);

	virtual ~AMateria(void);

	AMateria& operator=(AMateria const& a);

	std::string const& getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif