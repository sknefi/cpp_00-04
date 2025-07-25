#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie( const std::string &name ); // \p name should be const std::string &.
	~Zombie(); // Ideally should be virtual (to prevent memleaks in case of inheritance).
	
	void	announce( void ); 
};

void	randomChump( std::string name );
Zombie	*newZombie( std::string name );

#endif