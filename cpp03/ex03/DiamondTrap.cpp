#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap("NoName_clap_name"),
	FragTrap(),
	ScavTrap(),
	_name("NoName")
{
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_ad = FragTrap::_ad;
	std::cout << "DiamondTrap " << _name << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const std::string &name ) :
	ClapTrap(name + "_clap_name"),
	FragTrap(name),
	ScavTrap(name),
	_name(name)
{
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_ad = FragTrap::_ad;
	std::cout << "DiamondTrap " << _name << " parametric constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) :
	ClapTrap(other),
	FragTrap(other),
	ScavTrap(other),
	_name(other._name)
{
	_hp = other._hp;
	_energy = other._energy;
	_ad = other._ad;
	std::cout << "DiamondTrap " << _name << " copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other )
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
		_hp = other._hp;
		_energy = other._energy;
		_ad = other._ad;
	}
	std::cout << "DiamondTrap " << _name << " copy assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}


void	DiamondTrap::attack( const std::string &target )
{
	ScavTrap::attack(target);
}
