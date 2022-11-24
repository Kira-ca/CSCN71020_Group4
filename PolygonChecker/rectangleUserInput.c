/* Polygon Checker Group Project - Group 4 */
// CSCN71020-22F-Sec1 - Fall22 

// Implementation of rectangleUserInput Library for rectangleCheck 2.0 (2nd Approach)

#include "rectangleUserInput.h"												// Header file for rectangleUserInput Library				
#include "rectangleInputValidation.h"										// Header file for rectangleInputValidation Library

// This function GetUserInputPoints which also validate if they enter valid input (integer) and store the result in pointArrays[]
void GetUserInputPoints(int* pointArrays)
{
	char x[MAXSTRLEN];
	char y[MAXSTRLEN];
	char pointLetters[TWO] = { 'x', 'y' };

	// Prompt User for point x
	bool isValidEntryX;
		do
		{
			printf("%c: ", pointLetters[ZERO]);
			scanf_s("%s", x, MAXSTRLEN);
			// Check Input Validation
			isValidEntryX = ValidateUserInputForPoints(x);		// Validate if userInput for x point are an integer that may also include a negative integer
		} while (!isValidEntryX);
	
	// Prompt User for point x
	bool isValidEntryY = false;
	do
	{
		printf("%c: ", pointLetters[ONE]);
		scanf_s("%s", y, MAXSTRLEN);
		// Check Input Validation
		isValidEntryY = ValidateUserInputForPoints(y);		// Validate if userInput  for y point are an integer that may also include a negative integer
	} while (!isValidEntryY);

	// Convert x and y to int value then pass it back pointArrays[]

	pointArrays[ZERO] = atoi(x);
	pointArrays[ONE] = atoi(y);
}