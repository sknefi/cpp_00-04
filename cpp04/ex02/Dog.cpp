#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called." << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog( const Dog &src )
{
	std::cout << "Dog copy constructor called." << std::endl;
	_brain = new Brain();
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete _brain;
}

Dog	&Dog::operator = ( const Dog &src )
{
	std::cout << "Dog asignment operator called." << std::endl;
	if (this != &src)
	{
		_type = src._type;
		// _brain = src._brain; // this is shallow copy
		for (size_t i = 0; i < NUM_IDEAS; i++)
			_brain->ideas[i] = src._brain->ideas[i];
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "HAF HAF" << std::endl;
}
