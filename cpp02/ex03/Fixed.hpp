#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstdlib>
# include <cmath>


class Fixed
{
private:
	int					_rawBits;
	static const int	_fracBits;

public:
	// Constructors
	Fixed();						// constructor
	Fixed( const int num );			// int constructor
	Fixed( const float numF );		// float constructor
	Fixed( const Fixed &other );	// copy constructor

	// Destructor
	~Fixed();

	// Overloads
	Fixed	&operator = ( const Fixed &other );	// copy assignment operator overload
	
	bool	operator == ( const Fixed &x ) const;
	bool	operator != ( const Fixed &x ) const;
	bool	operator >= ( const Fixed &x ) const;
	bool	operator <= ( const Fixed &x ) const;
	bool	operator > ( const Fixed &x ) const;
	bool	operator < ( const Fixed &x ) const;

	Fixed	operator + ( const Fixed &x ) const;
	Fixed	operator - ( const Fixed &x ) const;
	Fixed	operator * ( const Fixed &x ) const;
	Fixed	operator / ( const Fixed &x ) const;

	Fixed	&operator ++ (); // pre-inc
	Fixed	&operator -- (); // pre-dec
	Fixed	operator ++ ( int ); // post-inc
	Fixed	operator -- ( int ); // post-dec

	// Member functions
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	int 	toInt( void ) const;
	float	toFloat( void ) const;

	static Fixed		&min( Fixed &a, Fixed &b );
	static Fixed		&max( Fixed &a, Fixed &b );
	static const Fixed	&min( const Fixed &a, const Fixed &b );
	static const Fixed	&max( const Fixed &a, const Fixed &b );
};

std::ostream &operator << (std::ostream &out, const Fixed &src);

#endif