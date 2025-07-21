#include <iostream>

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
			if ('a' <= argv[i][j] && argv[i][j] <= 'z')
				std::cout << (char)(argv[i][j] - 32);
			else
				std::cout << argv[i][j];
			j++;
		}
		if (i != argc - 1)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
