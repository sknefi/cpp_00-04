#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main()
{
	ScavTrap a("Alpha");
	ScavTrap b("Beta");

	a.attack("Beta");
	b.takeDamage(20);

	b.beRepaired(5);

	for (int i = 0; i < 11; ++i)
		a.attack("Dummy");

	for (int i = 0; i < 5; ++i) // Beta should die here
		b.takeDamage(20);

	b.beRepaired(3);

	a.guardGate();

	return (0);
}
