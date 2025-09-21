#include "Fixed.hpp"

int		main()
{
	std::cout << "=== CONSTRUCTORS TEST ===" << std::endl;
	Fixed a;						// Default constructor
	Fixed b(10);					// Int constructor
	Fixed c(42.42f);				// Float constructor
	Fixed d(b);						// Copy constructor
	
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl << std::endl;

	std::cout << "=== ASSIGNMENT OPERATOR TEST ===" << std::endl;
	a = Fixed(1234.4321f);
	std::cout << "a after assignment: " << a << std::endl << std::endl;

	std::cout << "=== COMPARISON OPERATORS TEST ===" << std::endl;
	Fixed x(5.5f);
	Fixed y(5.5f);
	Fixed z(3.3f);
	
	std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
	std::cout << "x == y: " << (x == y) << std::endl;
	std::cout << "x != z: " << (x != z) << std::endl;
	std::cout << "x > z: " << (x > z) << std::endl;
	std::cout << "z < x: " << (z < x) << std::endl;
	std::cout << "x >= y: " << (x >= y) << std::endl;
	std::cout << "z <= x: " << (z <= x) << std::endl;
	std::cout << "x < y: " << (x < y) << std::endl;
	std::cout << "y > z: " << (y > z) << std::endl;
	std::cout << "z >= x: " << (z >= x) << std::endl;
	std::cout << "x <= y: " << (x <= y) << std::endl << std::endl;

	std::cout << "=== ARITHMETIC OPERATORS TEST ===" << std::endl;
	Fixed num1(10.5f);
	Fixed num2(2.5f);
	
	std::cout << "num1: " << num1 << ", num2: " << num2 << std::endl;
	std::cout << "num1 + num2 = " << (num1 + num2) << std::endl;
	std::cout << "num1 - num2 = " << (num1 - num2) << std::endl;
	std::cout << "num1 * num2 = " << (num1 * num2) << std::endl;
	std::cout << "num1 / num2 = " << (num1 / num2) << std::endl << std::endl;

	std::cout << "=== INCREMENT/DECREMENT OPERATORS TEST ===" << std::endl;
	Fixed inc(5.0f);
	std::cout << "inc initial: " << inc << std::endl;
	std::cout << "++inc: " << ++inc << std::endl;
	std::cout << "inc++: " << inc++ << std::endl;
	std::cout << "inc after post-increment: " << inc << std::endl;
	std::cout << "--inc: " << --inc << std::endl;
	std::cout << "inc--: " << inc-- << std::endl;
	std::cout << "inc after post-decrement: " << inc << std::endl << std::endl;

	std::cout << "=== STATIC MIN/MAX FUNCTIONS TEST ===" << std::endl;
	Fixed min1(3.3f);
	Fixed min2(7.7f);
	std::cout << "min1: " << min1 << ", min2: " << min2 << std::endl;
	std::cout << "Fixed::min(min1, min2): " << Fixed::min(min1, min2) << std::endl;
	std::cout << "Fixed::max(min1, min2): " << Fixed::max(min1, min2) << std::endl;
	
	const Fixed const1(1.1f);
	const Fixed const2(2.2f);
	std::cout << "const1: " << const1 << ", const2: " << const2 << std::endl;
	std::cout << "Fixed::min(const1, const2): " << Fixed::min(const1, const2) << std::endl;
	std::cout << "Fixed::max(const1, const2): " << Fixed::max(const1, const2) << std::endl << std::endl;

	std::cout << "=== CONVERSION FUNCTIONS TEST ===" << std::endl;
	Fixed conv(42.42f);
	std::cout << "conv: " << conv << std::endl;
	std::cout << "conv.toInt(): " << conv.toInt() << std::endl;
	std::cout << "conv.toFloat(): " << conv.toFloat() << std::endl << std::endl;

	std::cout << "=== EDGE CASES TEST ===" << std::endl;
	Fixed zero(0);
	Fixed negative(-5.5f);
	std::cout << "zero: " << zero << std::endl;
	std::cout << "negative: " << negative << std::endl;
	std::cout << "negative + zero: " << (negative + zero) << std::endl;
	std::cout << "zero - negative: " << (zero - negative) << std::endl;

	return (EXIT_SUCCESS);
}
