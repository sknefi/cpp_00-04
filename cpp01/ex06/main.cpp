#include "Harl.hpp"

int		main( int argc, char *argv[] )
{
	Harl		harl;
	std::string	level;
	
	if (argc != 2)
	{
		std::cout << "There has to be only 1 argument" << std::endl;
		return (EXIT_FAILURE);
	}

	level = argv[1];
	harl.complain(level);
	return (EXIT_SUCCESS);
}