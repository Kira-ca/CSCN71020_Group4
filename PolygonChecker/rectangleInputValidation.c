/* Polygon Checker Group Project - Group 4 */
// CSCN71020-22F-Sec1 - Fall22 

// Implementation of rectangleInput Validation Library for rectangleCheck 2.0 (2nd Approach)

#include "global.h"																	// Header file for global Library
#include "rectangleInputValidation.h"												// Header file for rectangleInputValidation Library

// Validate if UserInput for Points are an integer that may also include a negative integer which either true, or false
bool ValidateUserInputForPoints(char* pointInString)
{
	int counterForMinus = 0;
	// Iterate through each character of a string (userInput)
	for (int i = 0; i < strlen(pointInString); i++)
	{
		// Count if user enter more than one minus sign 
		if (pointInString[i] == ASCIIMINUS)
		{
			counterForMinus++;						
		}

		// Validate if user input are an integer or a negative integer 
		if (!((pointInString[i] <= ASCIININE && pointInString[i] >= ASCIIZERO) || (pointInString[ZERO] == ASCIIMINUS && counterForMinus < TWO)))
			return false;
	}

	return true;
}