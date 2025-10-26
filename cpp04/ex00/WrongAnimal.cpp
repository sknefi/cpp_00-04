#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : 
	_type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &src )
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal	&WrongAnimal::operator = ( const WrongAnimal &src )
{
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	if (this != &src)
		_type = src._type;
	return (*this);
}

const std::string	&WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "SOUND IN WRONGANIMAL" << std::endl;
}
