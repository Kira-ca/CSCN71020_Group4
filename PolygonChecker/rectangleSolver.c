
#include "rectangleSolver.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


POINT GetRectanglePoints()
{
	int pointArrays[2];
	char pointLetters[2] = { 'x', 'y' };

	for (int i = 0; i < 2; i++)
	{
		bool isValidEntry = true;
		do
		{
			printf("%c: ", pointLetters[i]);

			if (scanf_s("%d", &pointArrays[i]) == 0)
			{
				printf("Invalid Entry!\n");
				while (getchar() != '\n');
			}
			else
			{
				isValidEntry = false;
			}
		} while (isValidEntry);
	}

	POINT assignedPoints = AssignPoints(pointArrays[0], pointArrays[1]);
	return assignedPoints;
}

POINT AssignPoints(int x, int y)
{
	POINT p;
	p.x = x;
	p.y = y;

	return p;
}

// Owen Implemented FixPointOrder Function
void FixPointOrder(POINT* array)
{
	int tempx;
	int tempy;

	for (int i = 0; i < 3; i++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (array[i + 1].x <= array[i].x && array[i + 1].y <= array[i].y)
			{
				tempx = array[i].x;
				tempy = array[i].y;
				array[i].x = array[i + 1].x;
				array[i].y = array[i + 1].y;
				array[i + 1].x = tempx;
				array[i + 1].y = tempy;
			}
		}
	}
	tempx = array[2].x;
	tempy = array[2].y;
	array[2].x = array[3].x;
	array[2].y = array[3].y;
	array[3].x = tempx;
	array[3].y = tempy;
}

void RectangleSolver()
{
	printf("Please enter 1st point x & y: \n");
	POINT point1 = GetRectanglePoints();

	printf("Please enter 2nd point x & y: \n");
	POINT point2 = GetRectanglePoints();

	printf("Please enter 3rd point x & y: \n");
	POINT point3 = GetRectanglePoints();

	printf("Please enter 4th point x & y: \n");
	POINT point4 = GetRectanglePoints();

	// sort x & y so that user Input order does not matter and still form a rectangle if it is true

	// Owen Implemented line 91 to 97
	POINT arrayOfPoints[4] = { point1, point2, point3, point4 };
	FixPointOrder(arrayOfPoints);

	point1 = arrayOfPoints[0];
	point2 = arrayOfPoints[1];
	point3 = arrayOfPoints[2];
	point4 = arrayOfPoints[3];


	// Validate Rectangle Points if repeated on the same point

	if (point1.x != point2.x && point1.y != point2.y ||
		point1.x != point3.x && point1.y != point3.y ||
		point1.x != point4.x && point1.y != point4.y ||
		point2.x != point3.x && point2.y != point3.y ||
		point2.x != point4.x && point2.y != point4.y ||
		point3.x != point4.x && point3.y != point4.y)
	{
		// Find the length of AB, BC, CD, DA
		// AB 
		double ABLength = (sqrt(pow(((double)point2.x - (double)point1.x), 2) + pow(((double)point2.y - (double)point1.y), 2)));
		printf("AB: %f\n", ABLength);
		double BCLength = (sqrt(pow(((double)point3.x - (double)point2.x), 2) + pow(((double)point3.y - (double)point2.y), 2)));
		printf("BC: %f\n", BCLength);
		double CDLength = (sqrt(pow(((double)point4.x - (double)point3.x), 2) + pow(((double)point4.y - (double)point3.y), 2)));
		printf("CD: %f\n", CDLength);
		double DALength = (sqrt(pow(((double)point1.x - (double)point4.x), 2) + pow(((double)point1.y - (double)point4.y), 2)));
		printf("DA: %f\n", DALength);

		// Find the length of points AC 
		double ACNonRightDiagonal = (sqrt(pow(((double)point3.x - (double)point1.x), 2) + pow(((double)point3.y - point1.y), 2)));
		printf("ACNonRight: %lf\n", ACNonRightDiagonal);

		double CANonRightDiagonal = (sqrt(pow(((double)point4.x - (double)point2.x), 2) + pow(((double)point4.y - point2.y), 2)));
		printf("ACNonRight: %lf\n", CANonRightDiagonal);

		// Find the hypothenus of C for right triangle ABC assuming it is a right triangle 
		double ACRightDiagonal = (sqrt(pow(((double)ABLength), (double)2) + pow(((double)BCLength), (double)2)));
		printf("ACRight: %lf\n", ACRightDiagonal);

		double CARightDiagonal = (sqrt(pow(((double)CDLength), (double)2) + pow(((double)DALength), (double)2)));
		printf("CDRight: %lf\n", CARightDiagonal);


		// Compare the length with the hypothenus result

		if (ABLength == CDLength && BCLength == DALength && ACNonRightDiagonal == ACRightDiagonal && CANonRightDiagonal == CARightDiagonal)
		{
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
		printf("You have entered repeated points\n");


}


