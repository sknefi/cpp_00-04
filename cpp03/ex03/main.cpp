#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int		main()
{
	std::cout << "\n=== Default Constructor Test ===\n";
	DiamondTrap *dtDefault = new DiamondTrap();
	dtDefault->whoAmI();
	dtDefault->attack("Training Dummy");
	delete dtDefault; // check destructor order

	std::cout << "\n=== Parametric Constructor Test ===\n";
	DiamondTrap alpha("Alpha");
	DiamondTrap beta("Beta");

	alpha.whoAmI();
	beta.whoAmI();

	std::cout << "\n=== Copy Constructor Test ===\n";
	DiamondTrap gamma(alpha);
	gamma.whoAmI();

	std::cout << "\n=== Assignment Operator Test ===\n";
	DiamondTrap delta("Delta");
	delta = beta;
	delta.whoAmI();

	std::cout << "\n=== Combat Simulation ===\n";
	alpha.attack("Beta");
	beta.takeDamage(30);
	beta.beRepaired(10);

	for (int i = 0; i < 5; ++i)
		alpha.attack("Dummy");

	std::cout << "\n=== Special Abilities ===\n";
	alpha.highFivesGuys();   // FragTrap ability
	beta.guardGate();        // ScavTrap ability

	std::cout << "\n=== Death Test ===\n";
	for (int i = 0; i < 5; ++i)
		beta.takeDamage(40); // should trigger death

	beta.beRepaired(10); // should fail because Beta is dead

	std::cout << "\n=== End of main() ===\n";
	return (0);
}
