#include "Zombie.hpp"

# define N 		10
# define NAME	"Beatles"

int		main()
{
	int		i;
	Zombie	*zHorde = zombieHorde(N, NAME);

	for (i = 0; i < N; i++)
	{
		zHorde[i].announce();
	}
	delete[] zHorde;
	
	return (EXIT_SUCCESS);
}