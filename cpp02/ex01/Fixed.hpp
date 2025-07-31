#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstdlib>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fracBits;

public:
	Fixed();									// constructor
	Fixed( const int num );						// int constructor
	Fixed( const float numF );					// float constructor
	Fixed( const Fixed &other );				// copy constructor
	Fixed &operator=( const Fixed &other );		// copy assignment operator overload
	~Fixed();									// desctructor

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	int 	toInt( void ) const;
	float	toFloat( void ) const;

};

std::ostream &operator << (std::ostream &out, const Fixed &src);

#endif