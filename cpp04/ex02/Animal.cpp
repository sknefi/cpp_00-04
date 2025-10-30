#include "Animal.hpp"

Animal::Animal() : 
	_type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal( const Animal &src )
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = src;
}

Animal::~Animal() 
{
	std::cout << "Animal destructor called." << std::endl;
}

Animal	&Animal::operator = ( const Animal &src )
{
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &src)
		_type = src._type;
	return (*this);
}

const std::string	&Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	std::cout << "SOUND IN ANIMAL" << std::endl;
}
