#include "Rectangle.h"											// Header file for Rectangle library

#include <stdio.h>												// is a header file that contains information to include the input/output related functions in our program
#include <stdbool.h>											// allows us to use bool datatype
#include <math.h>												// allows us to use sqrt type math functions

bool PointsToRectangle(int* arrayOfX, int* arrayOfY) {			// PointsToRectangle function is created that takes two arguments, both are a pointer of type int named arrayOfX and arrayOfY. It returns nothing.

	bool isARectangle = false;									// this variable will be used to check if the user inputted points form a rectangle or not

	int i = 0;					// i set to 0
	int j = 1;					// j set to 1

	int x1;	
	int y1;
	int x2;
	int y2;

	double length1;
	double length2;				// variables for length of 4 sides
	double length3;
	double length4;

	double arrayOfLengths[MAXSIZE];				// an array to store the length of 4 sides

	while (i < NUMBEROFPOINTS) {			// if i is less than NUMBEROFPOINTS then this while block continues executing

		if (j == 4) {						// j is set to 0 in this block to find length between the first and last point

			j = 0;
		}

		x1 = arrayOfX[i];					// getting coordinates of 1st point
		y1 = arrayOfY[i];

		x2 = arrayOfX[j];					// getting coordinates of the subsequent point
		y2 = arrayOfY[j];

		int sum = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));		// to find the length of side using two points we use the formula:
																			// ((x2 - x1)^2 + (y2 - y1)^2)^(1/2)
		if (i == 0) {											// if i = 0 then length1 is stored inside array at index 0

			length1 = sqrt((double)sum);						// doing sqrt (double because sqrt takes double as argument) of sum to find length of side
			arrayOfLengths[i] = length1;						// length is stored inside the array
		}
		else if (i == 1) {										// if i = 1 then length2 is stored inside array at index 1

			length2 = sqrt((double)sum);
			arrayOfLengths[i] = length2;
		}
		else if (i == 2) {										// if i = 2 then length3 is stored inside array at index 2

			length3 = sqrt((double)sum);
			arrayOfLengths[i] = length3;
		}
		else if (i == 3) {										// if i = 3 then length4 is stored inside array at index 3

			length4 = sqrt((double)sum);
			arrayOfLengths[i] = length4;
		}

		i++;							// incrementing i
		j++;							// incrementing j
	}

	// diagonal length check:
	double diagonalUsingPoints;						// this diagonal will store the length of diagonal found using corresponding points
	x1 = arrayOfX[0];								// taking coordinates of 1st point
	y1 = arrayOfY[0];

	x2 = arrayOfX[2];								// taking coordinates of 2nd point
	y2 = arrayOfY[2];

	// length of diagonal using the 2 points

	diagonalUsingPoints = sqrt((double)((x1 - x2) * (x1 - x2) + (y2 - y1) * (y2 - y1)));		// finding the length b/w 2 points using the formula sqrt((x2 - x1)^2 + (y2 - y1)^2)

	// length of diagonal assuming the diagonal forms a right angled triangle (so by using pythagoras theorem)

	double diagonalUsingPythagoras;	
	diagonalUsingPythagoras = sqrt((double)((length1 * length1) + (length2 * length2)));		// here finding the length of diagonal using pythagoras theorem.

	if (length1 == length3 && length2 == length4 && diagonalUsingPoints == diagonalUsingPythagoras) {				// Here the concept is used that the opposite sides of a rectangle are equal and the length of diagonals obtained from points and from pythagoras should be same

		isARectangle = true;									// isARectangle is set to true
	}

	double perimeter = Perimeter(arrayOfLengths, isARectangle);					// calling Perimeter function that takes two arguments, one double array of length and another a bool named isARectangle.
																				// the return value is stored in variable named perimeter
	if (isARectangle) {								// if isARectangle is true then this block gets executed

		printf("\nIt is a Rectangle:\n\n");									// this statement informs user that the points do form a Rectangle
		printf("The Perimeter of the Rectangle is: %.2lf\n", perimeter);	// this statement prints the perimeter of the rectangle using perimeter variable
	}
	else {											// if isARectangle is false then this block gets executed

		printf("\nIt is not a Rectangle: \n\n");								// this informs user that the points do not form a rectangle
		printf("The Perimeter of the figure is: %.2lf\n\n", perimeter);			// the perimeter of the figure is printed
	}
	
	double area = Area(arrayOfLengths, isARectangle);							// calling Area function that takes two arguments, one double array of length and another a bool named isARectangle.
																				// the return value is stored in variable named area.
	return isARectangle;								// returning a bool value
}

double Perimeter(double* arrayOfLengths) {			// Perimeter function is created that takes an argument, a pointer of type double named arrayOfLengths. It returns a double value.

	double perimeter = 0;							// a perimeter variable of type double is initialised									

	for (int i = 0; i < NUMBEROFPOINTS; i++) {		// if i is less than NUMBEROFPOINTS then this loop continues executing

		perimeter += arrayOfLengths[i];				// all the lengths are added one by one to perimeter variable
	}

	return perimeter;								// returning the value stored in perimeter
}

double Area(double* arrayOfLengths, bool isARectangle) {			// Area function is created that takes two arguments, one is a pointer of type double named arrayOfLengths and the other is a bool variable named isARectangle. It returns a double value.

	double area = 0;						// variable double is initialised and has value 0

	if (isARectangle) {											// if isARectangle is true i.e. it is a rectangle, then this if block gets executed

		area = arrayOfLengths[1] * arrayOfLengths[2];			// Since Area of a Rectangle is Length * Breadth, therefore the 2 consecutive length of sides are multiplied here

		printf("The area of the Rectangle is: %.2lf\n\n", area);			// the area of the Rectangle is printed
	}

	return area;										// returning the value stored in variable area, if it is not a rectangle then the value 0 is returned.
}