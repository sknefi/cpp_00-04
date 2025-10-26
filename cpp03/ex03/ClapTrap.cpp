#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_name("NoName"),
	_hp(10),
	_energy(10),
	_ad(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const std::string &name ):
	_name(name),
	_hp(10),
	_energy(10),
	_ad(0)
{
	std::cout << "Parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &other )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hp = other._hp;
		_energy = other._energy;
		_ad = other._ad;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor for " << _name << " called" << std::endl;
}

bool	ClapTrap::validStats( bool checkEnergy, bool checkHp ) const
{
	if (checkHp && _hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can't act because it has no hit points left." << std::endl;
		return (false);
	}
	if (checkEnergy && _energy == 0)
	{
		std::cout << "ClapTrap " << _name << " can't act because it has no energy left." << std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::attack( const std::string &target )
{
	if (!validStats())
		return ;
	//ClapTrap <name> attacks <target>, causing <damage> points of damage!
	_energy--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (!validStats(false))
		return ;
	if (amount >= _hp)
		_hp = 0;
	else
		_hp -= amount;
	std::cout << _name << " is taking " << amount << " points of damage!" << std::endl;

}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (!validStats())
		return ;
	_hp += amount;
	_energy--;
	std::cout << "ClapTrap " << _name << " is being repaired for " << amount << " hp." << std::endl; 
}
