#include "Character.hpp"

Character::Character() :
	_name("Unnamed")
{
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
	clear_slots();
	for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
	{
		if (src._slot[i])
			_slot[i] = src._slot[i]->clone();
	}
}

Character::~Character()
{
	clear_slots();
}

Character &Character::operator = ( const Character &src )
{
	if (this != &src)
	{
		clear_slots();
		for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
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
	for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
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

void	Character::clear_slots()
{
	for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
	{
		if (_slot[i])
		{
			delete _slot[i];
			_slot[i] = NULL;
		}
	}
}

int		Character::find_empty_slot_idx()
{
	for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
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
		std::cout << "Slot " << idx << " is not empty, use another slot." << std::endl;
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

	int		empty_idx = find_empty_slot_idx();
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
	_slot[idx] = NULL;
}
