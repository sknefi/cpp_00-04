#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	init_templates();
}

MateriaSource::MateriaSource( const MateriaSource &src )
{
	init_templates();
	*this = src;
}

MateriaSource::~MateriaSource()
{
	clear_templates();
}

MateriaSource &MateriaSource::operator = ( const MateriaSource &src )
{
	if (this != &src)
	{
		clear_templates();
		for (size_t i = 0; i < SIZE_OF_TEMPLATES; ++i)
		{
			if (src._templates[i])
				_templates[i] = src._templates[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::init_templates()
{
	for (size_t i = 0; i < SIZE_OF_TEMPLATES; ++i)
		_templates[i] = NULL;
}

void	MateriaSource::clear_templates()
{
	for (size_t i = 0; i < SIZE_OF_TEMPLATES; ++i)
	{
		if (_templates[i])
		{
			delete _templates[i];
			_templates[i] = NULL;
		}
	}
}

int		MateriaSource::find_empty_template_idx()
{
	for (size_t i = 0; i < SIZE_OF_TEMPLATES; ++i)
	{
		if (_templates[i] == NULL)
			return (static_cast<int>(i));
	}
	return (-1);
}

bool	MateriaSource::is_idx_valid( int idx, bool display_err )
{
	if (idx < 0 || idx >= SIZE_OF_TEMPLATES)
	{
		if (display_err)
			std::cout << "Template index " << idx << " is invalid." << std::endl;
		return (false);
	}
	return (true);
}

void	MateriaSource::learnMateria( AMateria *materia )
{
	if (!materia)
	{
		std::cout << "Cannot learn, materia is null." << std::endl;
		return ;
	}

	int empty_idx = find_empty_template_idx();
	if (empty_idx == -1)
	{
		std::cout << "MateriaSource is full, discarding materia." << std::endl;
		delete materia;
		return ;
	}
	_templates[empty_idx] = materia;
}

AMateria	*MateriaSource::createMateria( std::string const &type )
{
	for (size_t i = 0; i < SIZE_OF_TEMPLATES; ++i)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	return (NULL);
}
