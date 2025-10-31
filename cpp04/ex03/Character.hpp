#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define SIZE_OF_SLOT 4

class Character : public ICharacter
{
private:
	AMateria			*_slot[SIZE_OF_SLOT];
	std::string const	_name;

	void	init_slots();
	bool	is_idx_valid( int idx, bool display_err );
	int		find_empty_slot();

public:
	Character();
	Character( const std::string &name );
	Character( const Character &src );
	~Character();

	Character &operator = ( const Character &src );

	std::string const 	&getName() const;
	void				equip	( AMateria *m );
	void 				unequip	( int idx );
	void 				use		( int idx, ICharacter &target );

};

#endif
