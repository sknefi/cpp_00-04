#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	alpha, beta, gamma, denominator;

	denominator = ( (b.getY() - c.getY()) * (a.getX() - c.getX()) + 
					(c.getX() - b.getX()) * (a.getY() - c.getY()) );
	
	if (denominator == Fixed(0))
		return (false);
	
	alpha = ( (b.getY() - c.getY()) * (point.getX() - c.getX()) +
			  (c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
	 
	beta = ( (c.getY() - a.getY()) * (point.getX() - c.getX()) +
			 (a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
	 
	gamma = Fixed(1) - alpha - beta;

	return (alpha > 0 && beta > 0 && gamma > 0);
}
