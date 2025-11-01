#include "Character.hpp"

Character::Character() :
	_name("Unnamed")
{
	init_storage();
}

Character::Character( const std::string &name ) :
	_name(name)
{
	init_storage();
}

Character::Character( const Character &src ) :
	_name(src._name)
{
	init_storage();
	for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
	{
		if (src._slot[i])
			_slot[i] = src._slot[i]->clone();
	}
	for (size_t i = 0; i < SIZE_OF_FLOOR; ++i)
	{
		if (src._floor[i])
			_floor[i] = src._floor[i]->clone();
	}
}

Character::~Character()
{
	clear_storage();
}

Character	&Character::operator = ( const Character &src )
{
	if (this != &src)
	{
		clear_storage();
		init_storage();
		_name = src._name;
		for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
		{
			if (src._slot[i])
				_slot[i] = src._slot[i]->clone();
		}
		for (size_t i = 0; i < SIZE_OF_FLOOR; ++i)
		{
			if (src._floor[i])
				_floor[i] = src._floor[i]->clone();
		}
	}
	return (*this);
}

std::string const	&Character::getName() const
{
	return (_name);
}

void	Character::init_storage()
{
	for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
		_slot[i] = NULL;
	for (size_t i = 0; i < SIZE_OF_FLOOR; ++i)
		_floor[i] = NULL;
}

void	Character::clear_storage()
{
	for (size_t i = 0; i < SIZE_OF_SLOT; ++i)
	{
		if (_slot[i])
			delete _slot[i];
		_slot[i] = NULL;
	}
	for (size_t i = 0; i < SIZE_OF_FLOOR; ++i)
	{
		if (_floor[i])
			delete _floor[i];
		_floor[i] = NULL;
	}
}

int	Character::find_empty_slot_idx() const
{
	for (int i = 0; i < SIZE_OF_SLOT; ++i)
	{
		if (_slot[i] == NULL)
			return (i);
	}
	return (-1);
}

int	Character::find_empty_floor_idx() const
{
	for (int i = 0; i < SIZE_OF_FLOOR; ++i)
	{
		if (_floor[i] == NULL)
			return (i);
	}
	return (-1);
}

bool	Character::is_idx_valid( int idx, bool display_err ) const
{
	if (idx < 0 || idx >= SIZE_OF_SLOT)
	{
		if (display_err)
			std::cout << "Index " << idx << " is invalid." << std::endl;
		return (false);
	}
	return (true);
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

void	Character::equip( AMateria *m )
{
	if (!m)
	{
		std::cout << "Cannot equip null materia." << std::endl;
		return ;
	}

	int empty_idx = find_empty_slot_idx();
	if (empty_idx == -1)
	{
		std::cout << "No empty slot." << std::endl;
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

	int floor_idx = find_empty_floor_idx();
	if (floor_idx == -1)
	{
		std::cout << "Floor is full, call developer please." << std::endl;
		return ;
	}
	_floor[floor_idx] = _slot[idx];
	_slot[idx] = NULL;
}
