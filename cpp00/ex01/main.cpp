#include <iostream>
#include "PhoneBook.hpp"

int		main()
{
	PhoneBook	phoneBook;

	while (1)
	{
		if (std::cin.fail())
			break ;
		std::cout << "Enter command: ";
		std::string	command;
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.search();
		else if (command == "EXIT")
			break ;
		else
		{
			if (std::cin.fail())
				break ;			
			std::cout << "Invalid command" << std::endl;
		}
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);	
}
