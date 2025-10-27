#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called." << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &src )
{
	*this = src;
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat	&WrongCat::operator = ( const WrongCat &src )
{
	if (this != &src)
		_type = src._type;
	std::cout << "WrongCat asignment operator called." << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WRONG MEOW MEOW" << std::endl;
}