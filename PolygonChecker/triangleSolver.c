#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

void FindAnglesInTriangleAndPrint(double side1, double side2, double side3)
{
	// using cosine law to get the radian value of angle
	double angle1 = acos( (((side2 * side2) + (side3 * side3) - (side1 * side1)) / (2 * side2 * side3)) );
	angle1 *= DEGREECONVERSION; //converting radian to degree value

	// using cosine law to get the radian value of angle
	double angle2 = acos( (((side3 * side3) + (side1 * side1) - (side2 * side2)) / (2 * side3 * side1)) );
	angle2 *= DEGREECONVERSION; //converting radian to degree value

	double angle3 = DEGREETOTAL - angle1 - angle2; // doing the easy way to find 3rd angle

	//printing statement values
	printf_s("The 3 angles A, B, C in respect to your inputs are: %.2lf, %.2lf, %.2lf", angle1, angle2, angle3);
}