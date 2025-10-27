#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main()
{
	FragTrap a("Alpha");
	FragTrap b("Beta");

	a.attack("Beta");
	b.takeDamage(30);

	b.beRepaired(5);

	for (int i = 0; i < 11; ++i)
		a.attack("Dummy");

	for (int i = 0; i < 4; ++i) // Beta should die here
		b.takeDamage(30);

	b.beRepaired(3);

	a.highFivesGuys();

	return (0);
}
