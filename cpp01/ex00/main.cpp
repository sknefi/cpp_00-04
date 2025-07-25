#include "Zombie.hpp"

int		main()
{
	Zombie	*zombie = newZombie("Top G");
	
	zombie->announce();
	delete(zombie);
	
	randomChump("Chuck Norris");

	return (EXIT_SUCCESS);
}