#include "Harl.hpp"

int		main( void )
{
	Harl	harl;

	std::cout << std::endl << "=====DEBUG_LEVEL=====" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "=====INFO_LEVEL=====" << std::endl;;
	harl.complain("INFO");
	std::cout << std::endl << "=====WARNING_LEVEL=====" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "=====ERROR_LEVEL=====" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "=====not_valid_LEVEL=====" << std::endl;
	harl.complain("HIHI");

	return (EXIT_SUCCESS);
}