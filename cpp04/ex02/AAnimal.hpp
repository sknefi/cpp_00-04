#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
protected:
	std::string		_type;

public:
	AAnimal();
	AAnimal( const AAnimal &src );
	virtual ~AAnimal();

	AAnimal &operator = ( const AAnimal &src );

	const std::string	&getType() const;
	virtual void		makeSound() const = 0; // pure virtual
};

#endif
