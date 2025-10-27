#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called." << std::endl;
	_type = "Cat";
}

Cat::Cat( const Cat &src )
{
	*this = src;
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat	&Cat::operator = ( const Cat &src )
{
	if (this != &src)
		_type = src._type;
	std::cout << "Cat asignment operator called." << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "MEOW MEOW" << std::endl;
}
