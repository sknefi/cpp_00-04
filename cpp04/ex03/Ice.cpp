#include "Ice.hpp"

Ice::Ice() :
	AMateria("ice")
{
}

Ice::Ice( const Ice &src ) :
	AMateria(src)
{
	*this = src;
}

Ice::~Ice()
{
}

Ice		&Ice::operator = ( const Ice &src )
{
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

Ice		*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use( ICharacter &target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
