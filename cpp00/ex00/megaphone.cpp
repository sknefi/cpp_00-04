#include <iostream>
#include <cstdlib>
#include <cctype>

int	main(int argc, char *argv[])
{
	int		i;
	int		j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (EXIT_SUCCESS);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << static_cast<char> (std::toupper(argv[i][j]));
			j++;
		}
		/*
		if (i != argc - 1)
			std::cout << " ";
		*/
		i++;
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
