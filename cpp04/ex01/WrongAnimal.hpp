#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
protected:
	std::string		_type;

public:
	WrongAnimal();
	WrongAnimal( const WrongAnimal &src );
	~WrongAnimal();

	WrongAnimal &operator = ( const WrongAnimal &src );

	const std::string	&getType() const;
	void				makeSound() const;
};

#endif
