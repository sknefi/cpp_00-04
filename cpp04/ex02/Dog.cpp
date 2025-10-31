#include "Dog.hpp"

Dog::Dog() :
	_brain(new Brain())
{
	std::cout << "Dog default constructor called." << std::endl;
	_type = "Dog";
}

Dog::Dog( const Dog &src ) :
	AAnimal(src),
	_brain(new Brain(*src._brain))
{
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete _brain;
}

Dog	&Dog::operator = ( const Dog &src )
{
	std::cout << "Dog assignment operator called." << std::endl;
	if (this != &src)
	{
		AAnimal::operator=(src);
		*_brain = *src._brain;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "HAF HAF" << std::endl;
}
