#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define SIZE_OF_SLOT	4
# define SIZE_OF_FLOOR	100

class Character : public ICharacter
{
private:
	AMateria	*_slot[SIZE_OF_SLOT];
	AMateria	*_floor[SIZE_OF_FLOOR];
	std::string	_name;

		void	init_storage();
		void	clear_storage();
		int		find_empty_slot_idx() const;
		int		find_empty_floor_idx() const;
		bool	is_idx_valid( int idx, bool display_err ) const;

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
