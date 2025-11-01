#include "Cure.hpp"

Cure::Cure() :
	AMateria("cure")
{
}

Cure::Cure( const Cure &src ) :
	AMateria(src)
{
	*this = src;
}

Cure::~Cure()
{
}

Cure	&Cure::operator = ( const Cure &src )
{
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

Cure	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use( ICharacter &target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
