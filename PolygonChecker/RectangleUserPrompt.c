#define _CRT_SECURE_NO_WARNINGS					// allows us to ignore unsafe warnings
#include "RectangleUserPrompt.h"					// linking header file for RectangleUserInput library
#include <stdio.h>								// is a header file that contains information to include the input/output related functions in our program
#include <stdbool.h>							// allows us to use bool datatype
#include <stdlib.h>								// allows us to use atoi function
#include <string.h>								// allows us to use strlen function

bool FourPoints(int* arrayOfX, int* arrayOfY) {			// FourPoints function is created that takes two arguments, both are a pointer of type int named arrayOfX and arrayOfY. It returns bool value.

	char x[SIZE];										// two strings named are declared
	x[SIZE - 1] = NULLCHARACTER;

	char y[SIZE];
	y[SIZE - 1] = NULLCHARACTER;

	bool isInputValid = true;							// this variable will be used to tell if the input is valid or not

	printf("\nPlease enter points in order\n\n");				

	for (int i = 0; i < NUMBEROFPOINTS && isInputValid; i++) {			// if i is less than NUMBEROFPOINTS and input is valid then this loop keeps executing

		printf("Please enter x coordinate of %d point: ", i + 1);		// instructs user to enter x coordinate of i + 1 point
		scanf("%s", x);											// takes user input and stores it in variable x

		printf("Please enter y coordinate of %d point: ", i + 1);		// instructs user to enter y coordinate of i + 1 point
		scanf("%s", y);											// takes user input and stores it in variable y

		printf("\n");

		isInputValid = RectangleInputValidation(x, y);					// calling RectangleInputValidation that takes 2 string arguments (which are 2 user inputs) and returns a bool value. The returned value is assigned to isInputValid variable.

		if (isInputValid) {												// if input is valid then this if block gets executed

			arrayOfX[i] = atoi(x);										// atoi is used to convert the string to int and that is placed inside an integer array that stores only x values
			arrayOfY[i] = atoi(y);										// atoi is used to convert the string to int and that is placed inside an integer array that stores only y values
		}
		else {															// if the input is not valid then this else block gets executed

			printf("\nOnly numbers are allowed!\n\n");					
			isInputValid = false;										// isInputValid is set to false
		}
	}

	return isInputValid;												// isInputValid variable is returned
}
