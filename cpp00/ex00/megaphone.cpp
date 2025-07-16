#include <iostream>

int	get_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		len_arg;

	if (argc == 1)
		return (EXIT_FAILURE);
	i = 1;
	while (i < argc)
	{
		j = 0;
		len_arg = get_len(argv[i]);
		while (j < len_arg)
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
	std::cout << "\n";
	return (EXIT_SUCCESS);
}
