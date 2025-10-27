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
	virtual ~ClapTrap();

	virtual void	attack( const std::string &target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );
};

#endif
