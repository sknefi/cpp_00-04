#include "Zombie.hpp"

Zombie::Zombie() { };

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " has died..." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	_name = name;
}