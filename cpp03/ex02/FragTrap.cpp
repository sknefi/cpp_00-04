#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hp = 100;
	_energy = 100;
	_ad = 30;
	std::cout << "FragTrap " << _name << " default constructor called" << std::endl;
}

FragTrap::FragTrap( const std::string &name ) : ClapTrap( name )
{
	_hp = 100;
	_energy = 100;
	_ad = 30;
	std::cout << "FragTrap " << _name << " parametric constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap( other )
{
	*this = other;
	std::cout << "FragTrap " << _name << " copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=( const FragTrap &other )
{
	ClapTrap::operator=( other );
	std::cout << "FragTrap " << _name << " copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void	FragTrap::attack( const std::string &target )
{
	if (_hp == 0)
	{
		std::cout << "FragTrap " << _name << " can't act because it has no hit points left." << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << "FragTrap " << _name << " can't act because it has no energy left." << std::endl;
		return ;
	}
	_energy--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	if (_hp == 0)
	{
		std::cout << "FragTrap " << _name << " can't act because it has no hit points left." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
}
