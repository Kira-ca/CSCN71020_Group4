#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	/*According to the triangle inequality theorem, in order for three side lengths to form a triangle a + b > c or a + c > b or b + c > a,
	so this is added as a refactor*/

	if (side1 + side2 > side3 || side1 + side3 > side2 || side2 + side3 > side1) {
		printf("Your input is valid and forms a triangle\n");
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

double* FindAnglesInTriangleAndPrint(double side1, double side2, double side3)
{
	double angle[3];	//Refactor => an array of the angles was made so that they can be returned together

	// using cosine law to get the radian value of angle
	angle[0] = acos( (((side2 * side2) + (side3 * side3) - (side1 * side1)) / (2 * side2 * side3)) );
	angle[0] *= DEGREECONVERSION; //converting radian to degree value

	// using cosine law to get the radian value of angle
	angle[1] = acos( (((side3 * side3) + (side1 * side1) - (side2 * side2)) / (2 * side3 * side1)) );
	angle[1] *= DEGREECONVERSION; //converting radian to degree value

	angle[2] = DEGREETOTAL - angle[0] - angle[1]; // doing the easy way to find 3rd angle

	//printing statement values
	printf_s("The 3 angles A, B, C in respect to your inputs are: %.2lf, %.2lf, %.2lf\n", angle[0], angle[1], angle[2]);

	return angle;
}
