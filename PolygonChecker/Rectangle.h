#pragma once

#include <stdbool.h>						// allows us to use bool datatype

#define NUMBEROFPOINTS 4					// this constant signifies NUMBEROFPOINTS
#define MAXSIZE 50							// this constant signifies MAXSIZE

bool PointsToRectangle(int*, int*);			// function declaration for PointsToRectangle
double Perimeter(double*);					// function declaration for Perimeter
double Area(double*, bool);					// function declaration for Area