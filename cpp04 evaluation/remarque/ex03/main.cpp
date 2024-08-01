#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void tests()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");

	std::cout << "----Materia Creation----" << std::endl;
	AMateria *m1 = src->createMateria("ice");
	me->equip(m1);
	AMateria *m2 = src->createMateria("cure");
	me->equip(m2);
	AMateria *mfail = src->createMateria("fire");
	me->equip(mfail);

	std::cout << "----Use Materia----" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(-2, *bob);
	me->use(6, *bob);
	std::cout << std::endl;
	AMateria *m3 = src->createMateria("cure");
	me->equip(m3);
	AMateria *m4 = src->createMateria("ice");
	me->equip(m4);
	mfail = src->createMateria("earth");
	me->equip(mfail);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << "----Copy Character----" << std::endl;
	Character tom = Character("tom");
	AMateria *m5 = src->createMateria("cure");
	AMateria *m6 = src->createMateria("ice");
	AMateria *m7 = src->createMateria("ice");
	tom.equip(m5);
	tom.equip(m6);
	Character tommy = tom;
	tom.equip(m7);
	tom.use(0, *bob);
	tom.use(1, *bob);
	tom.use(2, *bob);
	tom.use(3, *bob);
	std::cout << std::endl;
	tommy.use(0, *bob);
	tommy.use(1, *bob);
	tommy.use(2, *bob);
	tommy.use(3, *bob);
	std::cout << std::endl;

	std::cout << "----Unequip----" << std::endl;
	tom.unequip(-1);
	tom.unequip(18);
	tom.unequip(3);
	tom.use(1, tommy);
	tom.unequip(1);
	delete m6;
	tom.use(1, *bob);
	tommy.use(1, tom);

	delete bob;
	delete me;
	delete src;
}

int main()
{
	tests();
	std::cout << std::endl;
	std::cout << "----Tests from the PDF----" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}