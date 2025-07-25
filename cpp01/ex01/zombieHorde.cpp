#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*zHorde = new Zombie[N];
	
	int		i;
	for (i = 0; i < N; i++)
	{
		zHorde[i].setName(name);
	}

	return (zHorde);
}
