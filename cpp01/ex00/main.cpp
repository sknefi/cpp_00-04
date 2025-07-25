#include "Zombie.hpp"

int		main()
{
	Zombie	*zombie = newZombie("Top G");
	
	zombie->announce();
	delete(zombie);
	randomChump();

	return (EXIT_SUCCESS);
}