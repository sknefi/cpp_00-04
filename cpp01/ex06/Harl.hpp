#ifndef HARL_CPP
# define HARL_CPP

# include <iostream>
# include <cstdlib>

# define LEVELS_COUNT 4

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

public:
	Harl( void );
	~Harl();
	void	complain( std::string level );
};

#endif