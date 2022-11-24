#pragma once

#include <stdio.h>
#define TWO			2
#define MAX_POINTS	4

typedef struct point
{
	int x;
	int y;
} POINT;

void RectangleSolver();

POINT AssignPoints(int, int);

POINT GetRectanglePoints();

void FixPointOrder(POINT*, POINT*, POINT*, POINT*); 
