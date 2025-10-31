#include "Character.hpp"

Character::Character() :
	_name("Unnamed")
{
	std::cout << "Character default constructor called." << std::endl;
	init_slots();
}

Character::Character( const std::string &name ) :
	_name(name)
{
	init_slots();
}

Character::Character( const Character &src ) :
	_name(src._name)
{
	std::cout << "Character copy constructor called." << std::endl;
	init_slots();
	for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
	{
		if (src._slot[i])
			_slot[i] = src._slot[i]->clone();
	}
}

Character::~Character()
{
	std::cout << "Character destructor called." << std::endl;
	for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
	{
		if (_slot[i])
		{
			delete _slot[i];
			_slot[i] = NULL;
		}
	}
}

Character &Character::operator = ( const Character &src )
{
	std::cout << "Character copy assignment operator called." << std::endl;
	if (this != &src)
	{
		for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
		{
			if (_slot[i])
			{
				delete _slot[i];
				_slot[i] = NULL;
			}
		}
		for (size_t i = 0; i < SIZE_OF_SLOT; i++)
		{
			if (src._slot[i])
				_slot[i] = src._slot[i]->clone();
		}
	}
	return (*this);
}

std::string const	&Character::getName() const
{
	return (_name);
}

void	Character::init_slots()
{
	for (size_t i = 0; i < SIZE_OF_SLOT; i++)
		_slot[i] = NULL;
}

bool	Character::is_idx_valid( int idx, bool display_err )
{
	if (idx < 0 || idx >= SIZE_OF_SLOT)
	{
		if (display_err)
			std::cout << "Index " << idx << " is invalid." << std::endl;
		return (false);
	}
	return (true);
}

int		Character::find_empty_slot()
{
	for (size_t i = 0; i < SIZE_OF_SLOT; i++)
	{
		if (_slot[i] == NULL)
			return (i);
	}
	return (-1);
}

void	Character::use( int idx, ICharacter &target )
{
	if (!is_idx_valid(idx, true))
		return ;
	if (!_slot[idx])
	{
		std::cout << "Slot " << idx << " is empty." << std::endl;
		return ;
	}
	_slot[idx]->use(target);
}

void	Character::equip( AMateria *m)
{
	if (!m)
	{
		std::cout << "Cannot equip null materia." << std::endl;
		return ;
	}

	int		empty_idx = find_empty_slot();
	if (empty_idx == -1)
	{
		std::cout << "No empty slot" << std::endl;
		return ;
	}
	_slot[empty_idx] = m;
}

void	Character::unequip( int idx )
{
	if (!is_idx_valid(idx, true))
		return ;
	if (!_slot[idx])
	{
		std::cout << "Slot " << idx << " is already empty." << std::endl;
		return ;
	}
	_slot[idx] = NULL;
}
