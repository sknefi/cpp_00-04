#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <cstdlib>

class Weapon
{
private:
	std::string	_type;

public:
	Weapon( std::string type );
	~Weapon();

	void				setType( const std::string &type );
	const std::string	&getType() const;
};

#endif