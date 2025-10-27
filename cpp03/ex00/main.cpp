#include "ClapTrap.hpp"

int		main()
{
	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	a.attack("Beta");
	b.takeDamage(0);

	b.beRepaired(5);

	for (int i = 0; i < 11; ++i)
		a.attack("Dummy");

	b.takeDamage(20);
	b.beRepaired(3);

	return (0);
}
