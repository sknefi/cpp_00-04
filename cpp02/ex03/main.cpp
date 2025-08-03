#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <cstdlib>

bool	bsp( Point const a, Point const b, Point const c, Point const point );

static void	printTest(const std::string& testName, bool expected, bool result)
{
	std::cout << testName << ": ";
	if (result == expected)
		std::cout << "✅ PASS";
	else
		std::cout << "❌ FAIL (expected " << (expected ? "true" : "false") 
				  << ", got " << (result ? "true" : "false") << ")";
	std::cout << std::endl;
}

int		main()
{
	std::cout << "=== BSP Tests ===" << std::endl << std::endl;

	// Define a standard triangle: (0,0), (4,0), (2,3)
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(2.0f, 3.0f);

	std::cout << "Triangle vertices: A(0,0), B(4,0), C(2,3)" << std::endl << std::endl;

	// Test 1: Point clearly inside the triangle
	Point inside(2.0f, 1.0f);
	printTest("Test 1 - Point inside triangle (2,1)", true, bsp(a, b, c, inside));

	// Test 2: Point clearly outside the triangle
	Point outside(5.0f, 5.0f);
	printTest("Test 2 - Point outside triangle (5,5)", false, bsp(a, b, c, outside));

	// Test 3: Point on vertex (should be false for strictly inside)
	printTest("Test 3 - Point on vertex A (0,0)", false, bsp(a, b, c, a));

	// Test 4: Point on edge (should be false for strictly inside)
	Point onEdge(2.0f, 0.0f); // midpoint of AB
	printTest("Test 4 - Point on edge AB (2,0)", false, bsp(a, b, c, onEdge));

	// Test 5: Degenerate triangle (collinear points)
	Point d1(0.0f, 0.0f);
	Point d2(2.0f, 0.0f);
	Point d3(4.0f, 0.0f); // All points on same line
	Point testPoint(1.0f, 0.0f);
	printTest("Test 5 - Degenerate triangle", false, bsp(d1, d2, d3, testPoint));

	// Test 6: Different triangle with negative coordinates
	Point n1(-1.0f, -1.0f);
	Point n2(1.0f, -1.0f);
	Point n3(0.0f, 1.0f);
	Point origin(0.0f, 0.0f);
	printTest("Test 6 - Point at origin in triangle", true, bsp(n1, n2, n3, origin));

	std::cout << std::endl << "=== All Tests Complete ===" << std::endl;

	return (EXIT_SUCCESS);
}
