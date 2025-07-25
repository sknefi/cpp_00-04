#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <cstdlib>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon		*_weapon;

public:
	HumanB( const std::string &name );
	~HumanB();

	void	attack() const;
	void	setWeapon( Weapon &weapon );
	
};

#endif