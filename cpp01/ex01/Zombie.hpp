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
	Zombie();
	~Zombie();
	
	void	announce();
	void	setName( const std::string name );
};

Zombie	*zombieHorde( int N, std::string name );

#endif