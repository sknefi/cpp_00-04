#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called." << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat( const Cat &src )
{
	std::cout << "Cat copy constructor called." << std::endl;
	_brain = new Brain();
	*this = src;
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
		_type = src._type;
		// _brain = src._brain; // this is shallow copy
		for (size_t i = 0; i < NUM_IDEAS; i++)
			_brain->ideas[i] = src._brain->ideas[i];
	}
	std::cout << "Cat asignment operator called." << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "MEOW MEOW" << std::endl;
}
