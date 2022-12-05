#pragma once

/* Polygon Checker Group Project - Group 4 */
// CSCN71020-22F-Sec1 - Fall22 

// Header file rectangleSolver Library for rectangleCheck 2.0 (2nd Approach)

#include <stdio.h>
#include <stdbool.h>																// Use for boolean data type (true/false)


typedef struct point																// A typedef struct used as a template to assign x and y of a point
{
	int x;
	int y;
} POINT;

void RectangleSolver();																// A function prototype for RectangleSolver

POINT AssignPoints(int, int);														// A function prototype for AssignPoints

POINT GetRectanglePoints();															// A function prototype for GetRectanglePoints

void FixPointOrder(POINT*);															// A function prototype for FixPointOrder

double FindDiagonalOfNonRightTriangle(POINT, POINT);								// A function prototype for FindDiagonalOfNonRightTriangle

double FindHypotenuseOfRightTriangle(double, double);								// A function prototype for FindHypotenusOfRightTriangle

bool ArePointsDuplicated(POINT point1, POINT point2, POINT point3, POINT point4);	// A function prototype for ArePointsDuplicated

double FindArea(double, double, double, double);							// A function prototype for FindArea

double FindPerimeter(double, double, double, double);						// A function prototype for FindPerimeter