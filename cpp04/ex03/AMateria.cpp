#include "AMateria.hpp"

AMateria::AMateria() :
	_type("DefaultMateria")
{
}

AMateria::AMateria( const std::string &type ) :
	_type(type)
{
}

AMateria::AMateria( const AMateria &src )
{
	*this = src;	
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator = ( const AMateria &src )
{
	if (this != &src)
		_type = src._type;
	return (*this);
}

std::string const	&AMateria::getType() const 
{
	return (_type);
}

void	AMateria::use( ICharacter &target )
{
	(void)target;
	std::cout << "* what do u expect traveler, this does nothing :) *" << std::endl; 
}
