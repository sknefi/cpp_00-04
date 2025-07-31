#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_fracBits = 8;

Fixed::Fixed()
	: _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num )
	:_rawBits(num << _fracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float numF )
	:_rawBits(roundf(numF * (1 << _fracBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=( const Fixed &other )
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		_rawBits = other.getRawBits();
	
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits( int const raw)
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

std::ostream	&operator<<( std::ostream &out, const Fixed &fixed )
{
	out << fixed.toFloat();
	return (out);
}
