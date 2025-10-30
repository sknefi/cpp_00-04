#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain( const Brain &src )
{
	*this = src;
	std::cout << "Brain copy consturctor called." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain desctructor called." << std::endl;
}

Brain	&Brain::operator = ( const Brain &src )
{
	if (this != &src) 
	{
		for (size_t i = 0; i < NUM_IDEAS; i++)
			ideas[i] = src.ideas[i];
	}
	std::cout << "Brain assignement operator called." << std::endl;
	return (*this);
}
