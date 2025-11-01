#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		std::cout << "=== Subject sample ===" << std::endl;
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

	std::cout << std::endl << "=== Extended tests ===" << std::endl;
	{
		MateriaSource	source;
		source.learnMateria(new Ice());
		source.learnMateria(new Cure());
		source.learnMateria(new Ice());
		source.learnMateria(new Cure());
		source.learnMateria(new Ice()); // should be discarded because storage is full

		Character	alice("Alice");
		Character	bob("Bob");

		AMateria*	floor[8] = { NULL };
		size_t		floorCount = 0;

		AMateria* ice1 = source.createMateria("ice");
		AMateria* cure1 = source.createMateria("cure");
		AMateria* ice2 = source.createMateria("ice");
		AMateria* cure2 = source.createMateria("cure");
		AMateria* unknown = source.createMateria("fire");
		if (!unknown)
			std::cout << "Unknown materia request returned nullptr as expected." << std::endl;

		alice.equip(ice1);
		alice.equip(cure1);
		alice.equip(ice2);
		alice.equip(cure2);

		alice.use(0, bob);
		alice.use(1, bob);

		AMateria* overflow = source.createMateria("ice");
		alice.equip(overflow); // inventory is full, so character keeps the original four
		if (overflow)
		{
			std::cout << "Inventory full; deleting overflow materia manually." << std::endl;
			delete overflow;
		}

		Character	copyAlice(alice);
		Character	assigned("Assigned");
		assigned = alice;

		alice.use(2, bob);
		copyAlice.use(2, bob);
		assigned.use(2, bob);

		alice.unequip(1);
		floor[floorCount++] = cure1; // we still own this pointer, so delete it later
		alice.use(1, bob); // now empty
		copyAlice.use(1, bob); // copy kept its own clone
		assigned.use(1, bob);  // assignment clone still works

		alice.use(5, bob); // out of range

		for (size_t i = 0; i < floorCount; ++i)
		{
			delete floor[i];
			floor[i] = NULL;
		}
	}

	return 0;
}
