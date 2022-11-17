#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	/*According to the triangle inequality theorem, in order for three side lengths to form a triangle a + b > c or a + c > b or b + c > a, 
	so this is added as a refactor*/
	
	if (side1 + side2 > side3 || side1 + side3 > side2 || side2 + side3 > side1) {
		printf("Your input is valid and forms a triangle\n");
		printf("The triangle formed is a/an:\n");
	}
	




	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}


