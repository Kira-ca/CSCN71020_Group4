#pragma once

#include <stdio.h>
#include <stdbool.h>
#define ZERO		0
#define ONE			1
#define TWO			2
#define THREE		3
#define FOUR		4
#define FIVE		5
#define THEPOWOFTWO 2
#define MAX_POINTS	4

typedef struct point																// A typedef struct used as a template to assign x and y of a point
{
	int x;
	int y;
} POINT;

void RectangleSolver();																// A function prototype for RectangleSolver

POINT AssignPoints(int, int);														// A function prototype for AssignPoints

POINT GetRectanglePoints();															// A function prototype for GetRectanglePoints

void FixPointOrder(POINT*, POINT*, POINT*, POINT*);									// A function prototype for FixPointOrder

double FindDiagonalOfNonRightTriangle(POINT, POINT);								// A function prototype for FindDiagonalOfNonRightTriangle

double FindHypotenuseOfRightTriangle(double, double);								// A function prototype for FindHypotenusOfRightTriangle

bool ArePointsDuplicated(POINT point1, POINT point2, POINT point3, POINT point4);	// A function prototype for ArePointsDuplicated