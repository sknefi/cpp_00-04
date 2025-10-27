#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_name("NoName"),
	_hp(10),
	_energy(10),
	_ad(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const std::string &name ):
	_name(name),
	_hp(10),
	_energy(10),
	_ad(0)
{
	std::cout << "ClapTrap parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other )
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &other )
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
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
	std::cout << "ClapTrap destructor for " << _name << " called" << std::endl;
}

void	ClapTrap::attack( const std::string &target )
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can't act because it has no hit points left." << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << "ClapTrap " << _name << " can't act because it has no energy left." << std::endl;
		return ;
	}
	_energy--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can't act because it has no hit points left." << std::endl;
		return ;
	}
	if (amount >= _hp)
		_hp = 0;
	else
		_hp -= amount;
	std::cout << "ClapTrap " << _name << " is taking " << amount << " points of damage!" << std::endl;

}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can't act because it has no hit points left." << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << "ClapTrap " << _name << " can't act because it has no energy left." << std::endl;
		return ;
	}
	_hp += amount;
	_energy--;
	std::cout << "ClapTrap " << _name << " is being repaired for " << amount << " hp." << std::endl; 
}
