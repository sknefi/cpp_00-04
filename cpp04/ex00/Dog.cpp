#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called." << std::endl;
	_type = "Dog";
}

Dog::Dog( const Dog &src )
{
	*this = src;
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

Dog	&Dog::operator = ( const Dog &src )
{
	if (this != &src)
		_type = src._type;
	std::cout << "Dog asignment operator called." << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "HAF HAF" << std::endl;
}
