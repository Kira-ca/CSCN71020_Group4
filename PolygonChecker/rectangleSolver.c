/* Polygon Checker Group Project - Group 4 */
// CSCN71020-22F-Sec1 - Fall22 

// Implementation of rectangleCheck2.0 (2nd Approach) Library
/********************************************************************************************************************************************
* Requirements: 
	Add a new feature to the application program to accept four points. Each point is an x,y pair. You may ask the user to enter the x and y one at a time, or at once and split the input yourself. There should be some validation on the user input to ensure you are given proper values. Once given the four points, generate four lines and determine if these lines form a rectangle. You may find it useful to re-use your triangle angle code to assist this, but you may use a unique function to determine if the lines make a rectangle. Report the shape's perimeter, and if it is a rectangle also report its area.
*/
/********************************************************************************************************************************************
	*This program use the 2nd approach:

	- The second approach is to write code to determine which "corner" each point is, and then connect the corners to form the shape. Using this approach, no matter the order the points are entered, no lines will cross. This approach is worth extra marks.
//********************************************************************************************************************************************
*/

#include "rectangleSolver.h"													// Header file for rectangleSolver Library
#include "rectangleUserInput.h"													// Header file for rectangleUserInput Library
#include <stdio.h>
#include <stdbool.h>															// Use for boolean data type (true/false)
#include <math.h>																// Use for sqrt() and pow() methods

// A function that get points from userInput and return point of struct (x,y)
POINT GetRectanglePoints()
{
	int pointArrays[TWO];
	char pointLetters[TWO] = { 'x', 'y' };

	// This function get userInput in string, then validate if valid. If false, it will reprompt, else convert the userInput in string to numbers and store it in the pointArrays[]
	GetUserInputPoints(&pointArrays);
	
	// Assign x and y of each point to the struct of POINT which return back the structure 
	POINT assignedPoints = AssignPoints(pointArrays[ZERO], pointArrays[ONE]);
	return assignedPoints;
}

// A function that assign point x and y to a point struct and return the structure
POINT AssignPoints(int x, int y)
{
	POINT p;
	p.x = x;
	p.y = y;

	return p;
}

// Owen wrote FixPointOrder Function
void FixPointOrder(POINT* array)
{
	//declraing temp variables to swap values of points
	int tempx;
	int tempy;

	//looping through check 4 times to fully organize points
	for (int i = 0; i < THREE; i++)
	{
		for (int i = 0; i < THREE; i++)
		{
			//swapping point order to the points with the lowest values first
			if (array[i + ONE].x <= array[i].x && array[i + ONE].y <= array[i].y)
			{
				tempx = array[i].x;
				tempy = array[i].y;
				array[i].x = array[i + ONE].x;
				array[i].y = array[i + ONE].y;
				array[i + ONE].x = tempx;
				array[i + ONE].y = tempy;
			}
		}
	}
	//swapping the last 2 points in arrayOfPoints to make the points go in order of drawing the ractangle
	tempx = array[MAX_POINTS-TWO].x;
	tempy = array[MAX_POINTS-TWO].y;
	array[MAX_POINTS-TWO].x = array[MAX_POINTS-ONE].x;
	array[MAX_POINTS-TWO].y = array[MAX_POINTS-ONE].y;
	array[MAX_POINTS-ONE].x = tempx;
	array[MAX_POINTS-ONE].y = tempy;
}

// A function that host all the functions for finding rectangle from 4 points
void RectangleSolver()
{
	bool isValidRectangle = false;

	printf("Please enter 1st point x & y: \n");
	POINT point1 = GetRectanglePoints();

	printf("Please enter 2nd point x & y: \n");
	POINT point2 = GetRectanglePoints();

	printf("Please enter 3rd point x & y: \n");
	POINT point3 = GetRectanglePoints();

	printf("Please enter 4th point x & y: \n");
	POINT point4 = GetRectanglePoints();

	// Owen Covach wrote line 111 to 121
	
	// sort x & y so that user Input order does not matter and still form a rectangle if it is true
	
	//creating an array of the points for easier checks
	POINT arrayOfPoints[MAX_POINTS] = { point1, point2, point3, point4 };
	FixPointOrder(arrayOfPoints);

	//setting actual point variables to new order for program use
	point1 = arrayOfPoints[ZERO];
	point2 = arrayOfPoints[ONE];
	point3 = arrayOfPoints[TWO];
	point4 = arrayOfPoints[THREE];


	// Validate Rectangle Points if repeated on the same point

	bool isDuplicate = ArePointsDuplicated(point1, point2, point3, point4);

	// If all points are not duplicated then it can proceed to perform calculations
	if(!isDuplicate)
	{
		// Find the length of AB, BC, CD, DA for all 4 points 
		double ABLength = FindDiagonalOfNonRightTriangle(point1, point2);

		double BCLength = FindDiagonalOfNonRightTriangle(point2, point3);
	
		double CDLength = FindDiagonalOfNonRightTriangle(point3, point4);

		double DALength = FindDiagonalOfNonRightTriangle(point4, point1);

		// Find the length of points AC and CA for its diagonal
		double ACNonRightDiagonal = FindDiagonalOfNonRightTriangle(point1, point3);

		double CANonRightDiagonal = FindDiagonalOfNonRightTriangle(point2, point4);

		// Find the hypotenuse for right triangle AC and CA assuming it is a right triangle 
		double ACRightDiagonal = FindHypotenuseOfRightTriangle(ABLength, BCLength);

		double CARightDiagonal = FindHypotenuseOfRightTriangle(CDLength, DALength);

		// Compare the diagonal length with the hypothenuse length result if they are equal then it is a rectangle
		// We used to 2 different formulas (to find the length of diagonal length and hypotenuse length)
		// We have to check all possible length and Diagonal of both non-right triangle diagonal and right triangle hypotenuse (diagonal) because user may enter points that are not neccessary valid to form 90 degree angle. Also this ensure that no lines will cross each other.
		if (ABLength == CDLength && BCLength == DALength && ACNonRightDiagonal == ACRightDiagonal && CANonRightDiagonal == CARightDiagonal)
		{
			// Calculate The Area of a Rectangle
			FindArea(ABLength, BCLength, CDLength, DALength);

			// Calculate The Perimeter of a Rectangle
			FindPerimeter(ABLength, BCLength, CDLength, DALength);

			printf("\nIt is a Rectangle\n");
			printf("\n*************\n");
			printf("*           *\n");
			printf("*           *\n");
			printf("*           *\n");
			printf("*************\n");

		}
		else
			printf("It is not a Rectangle\n");
	}
	else
		printf("You have entered duplicated points\n");
}

// Find the Diagonal for all 4 points to determine its Length which return the result in double
double FindDiagonalOfNonRightTriangle(POINT pointA, POINT pointB)
{
	double diagonalResult = (sqrt(pow(((double)pointB.x - (double)pointA.x), THEPOWOFTWO) + pow(((double)pointB.y - (double)pointA.y), THEPOWOFTWO)));
	return diagonalResult;
}

// Calculate Hypotenuse of a Right Triangle if all 4 points form a rectangle since rectangle split in half will be a right triangle with a 90 degree angle and the function return the calculated result in double
double FindHypotenuseOfRightTriangle(double lengthA, double lengthB)
{
	double hypotenuseResult = (sqrt(pow(((double)lengthA), (double)THEPOWOFTWO) + pow(((double)lengthB), (double)THEPOWOFTWO)));
	return hypotenuseResult;
}

// Validate if x and y points between 2 points (point1 to 4) to determine if they have been entered which return true, else false
bool ArePointsDuplicated(POINT point1, POINT point2, POINT point3, POINT point4)
{
	if (point1.x == point2.x && point1.y == point2.y ||
		point1.x == point3.x && point1.y == point3.y ||
		point1.x == point4.x && point1.y == point4.y ||
		point2.x == point3.x && point2.y == point3.y ||
		point2.x == point4.x && point2.y == point4.y ||
		point3.x == point4.x && point3.y == point4.y)
	{
		return true;
	}
	else
		return false;
}

// Calculate for Area of Rectangle
void FindArea(double ABLength, double BCLength, double CDLength, double DALength)
{
	double Area1 = 0;
	double Area2 = 0;

	// A formula to solve for Area of a Rectangle
	Area1 = ABLength * BCLength;
	Area2 = CDLength * DALength;

	// Validate length of 2 different side to ensure that they are equal
	if (Area1 == Area2)
	{
		printf("Area: %.3lf\n", Area1);
	}
	else
		printf("Invalid Area\n");
}

// Calculate for Perimeter of Rectangle
void FindPerimeter(double ABLength, double BCLength, double CDLength, double DALength)
{
	double Perimeter1 = 0;		
	double Perimeter2 = 0;

	// A formula to solve for Perimeter of a Rectangle
	Perimeter1 = 2 * (ABLength + BCLength);
	Perimeter2 = 2 * (CDLength + DALength);

	// Validate length of 2 different side to ensure that they are equal
	if (Perimeter1 == Perimeter2)
	{
		printf("Perimeter: %.3lf\n", Perimeter1);
	}
	else
		printf("Invalid Perimeter\n");

}