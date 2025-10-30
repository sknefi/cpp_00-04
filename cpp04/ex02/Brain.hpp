#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define NUM_IDEAS 100

class Brain
{
public:
	std::string		ideas[NUM_IDEAS];
	
	Brain();
	Brain( const Brain &src );
	~Brain();

	Brain	&operator = ( const Brain &src );
};

#endif