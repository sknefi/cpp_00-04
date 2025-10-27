#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{

private:
	Brain	*_brain;

public:
	Dog();
	Dog( const Dog &src );
	~Dog();

	Dog &operator = ( const Dog &src );

	void	makeSound() const;
};

#endif
