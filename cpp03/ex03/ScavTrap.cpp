#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	// name is set in ClapTrap constructor
	_hp = 100;
	_energy = 50;
	_ad = 20;
	std::cout << "ScavTrap " << _name << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap( const std::string &name ) : ClapTrap( name )
{
	// name is set in ClapTrap constructor
	_hp = 100;
	_energy = 50;
	_ad = 20;
	std::cout << "ScavTrap " << _name << " parametric constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap( other )
{
	*this = other;
	std::cout << "ScavTrap " << _name << " copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other )
{
	ClapTrap::operator=( other );
	std::cout << "ScavTrap " << _name << " copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void	ScavTrap::attack( const std::string &target )
{
	if (!validStats())
		return ;
	_energy--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (!validStats(false))
		return ;
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}