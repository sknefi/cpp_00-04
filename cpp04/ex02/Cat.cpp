#include "Cat.hpp"

Cat::Cat() :
	_brain(new Brain())
{
	std::cout << "Cat default constructor called." << std::endl;
	_type = "Cat";
}

Cat::Cat( const Cat &src ) :
	AAnimal(src),
	_brain(new Brain(*src._brain))
{
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete _brain;
}

Cat	&Cat::operator = ( const Cat &src )
{
	if (this != &src)
	{
		AAnimal::operator=(src);
		*_brain = *src._brain; // deep copy, copies every single idea from srcbrain to src
		// _brain = src._brain; // this would be shallow copy
	}
	std::cout << "Cat assignment operator called." << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "MEOW MEOW" << std::endl;
}
