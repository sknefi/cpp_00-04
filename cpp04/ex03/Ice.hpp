#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice( const Ice &src );
		~Ice();

		Ice 	&operator = ( const Ice &src );
		
		Ice		*clone	() const;
		void	use		( ICharacter &target );	
};

#endif