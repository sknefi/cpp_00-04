#include "Zombie.hpp"

Zombie::Zombie() { };

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " has died..." << std::endl;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( const std::string name )
{
	_name = name;
}