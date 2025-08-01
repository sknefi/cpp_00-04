#include "Harl.hpp"

Harl::Harl( void ) { };

Harl::~Harl() { };

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string levels[LEVELS_COUNT] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void		(Harl::*f[LEVELS_COUNT])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	int		i;
	for (i = 0; i < LEVELS_COUNT; i++)
	{
		if (level == levels[i])
		{
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "Level: " << level << " is not valid" << std::endl;
}
