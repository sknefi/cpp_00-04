#include "Fixed.hpp"

const int	Fixed::_fracBits = 8;

Fixed::Fixed()
	: _rawBits(0)
{
}

Fixed::Fixed( const int num )
	:_rawBits(num << _fracBits)
{
}

Fixed::Fixed( const float numF )
	:_rawBits(roundf(numF * (1 << _fracBits)))
{
}

Fixed::Fixed( const Fixed &other )
{
	*this = other;
}

Fixed	&Fixed::operator = ( const Fixed &other )
{
	if (this != &other)
		_rawBits = other.getRawBits();
	
	return (*this);
}

Fixed::~Fixed()
{
}

bool	Fixed::operator == ( const Fixed &x ) const
{
	return (_rawBits == x._rawBits);
}

bool	Fixed::operator != ( const Fixed &x ) const
{
	return (_rawBits != x._rawBits);
}

bool	Fixed::operator >= ( const Fixed &x ) const
{
	return (_rawBits >= x._rawBits);
}

bool	Fixed::operator <= ( const Fixed &x ) const
{
	return (_rawBits <= x._rawBits);
}
bool	Fixed::operator > ( const Fixed &x ) const
{
	return (_rawBits > x._rawBits);
}

bool	Fixed::operator < ( const Fixed &x ) const
{
	return (_rawBits < x._rawBits);
}

Fixed	Fixed::operator + ( const Fixed &x ) const
{
	return (Fixed(toFloat() + x.toFloat()));
}

Fixed	Fixed::operator - ( const Fixed &x ) const
{
	return (Fixed(toFloat() - x.toFloat()));
}

Fixed	Fixed::operator * ( const Fixed &x ) const
{
	return (Fixed(toFloat() * x.toFloat()));
}

Fixed	Fixed::operator / ( const Fixed &x ) const
{
	return (Fixed(toFloat() / x.toFloat()));
}

Fixed	&Fixed::operator ++ ()
{
	_rawBits++;
	return (*this);
}

Fixed	&Fixed::operator -- ()
{
	_rawBits--;
	return (*this);
}

Fixed	Fixed::operator ++ ( int )
{
	Fixed	temp = *this;
	_rawBits++;
	return (temp);
}

Fixed	Fixed::operator -- ( int )
{
	Fixed	temp = *this;
	_rawBits--;
	return (temp);
}

std::ostream	&operator << ( std::ostream &out, const Fixed &fixed )
{
	out << fixed.toFloat();
	return (out);
}

int		Fixed::getRawBits( void ) const
{
	return (_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	_rawBits = raw;
}

int		Fixed::toInt( void ) const
{
	return (_rawBits >> _fracBits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)_rawBits / (float)(1 << _fracBits));
}

Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b )
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::max( const Fixed &a, const Fixed &b )
{
	return (a > b ? a : b);
}
