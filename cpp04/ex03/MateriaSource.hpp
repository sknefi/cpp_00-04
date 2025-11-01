#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include <iostream>

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define SIZE_OF_TEMPLATES 4

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_templates[SIZE_OF_TEMPLATES];

	void	init_templates();
	bool	is_idx_valid( int idx, bool display_err );
	int		find_empty_template_idx();
	void	clear_templates();

public:
	MateriaSource();
	MateriaSource( const MateriaSource &src );
	~MateriaSource();

	MateriaSource &operator = ( const MateriaSource &src );

	void		learnMateria	(AMateria*);
	AMateria	*createMateria	(std::string const &type);
};


#endif
