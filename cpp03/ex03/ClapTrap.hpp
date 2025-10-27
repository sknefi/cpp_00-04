#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hp;
	unsigned int	_energy;
	unsigned int	_ad;

public:
	ClapTrap();
	ClapTrap( const std::string &name );
	ClapTrap( const ClapTrap &other );
	ClapTrap &operator=( const ClapTrap &other );
	virtual ~ClapTrap(); // check it without, just to see what happens
	 
	virtual void	attack( const std::string &target ); // this will be overridden in the derived classes
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );
};

#endif
