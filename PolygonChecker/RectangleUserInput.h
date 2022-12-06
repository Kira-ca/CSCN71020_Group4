#pragma once

#include "RectangleInputValidation.h"			// linking header file for RectangleInputValidation
#include <stdbool.h>							// allows us to use bool datatype

#define NUMBEROFPOINTS 4						// this constant signifies number of points
#define SIZE 20									// this constant signifies size

bool FourPoints(int*, int*);					// function declaration for FourPoints