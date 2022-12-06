#include "RectangleInputValidation.h"								// Header file for RectangleInputValidation library
#include <stdbool.h>												// allows us to use bool datatype
#include <string.h>													// allows us to use strlen function

bool RectangleInputValidation(char* x, char* y) {					// RectangleInputValidation function is created that takes two arguments, both are a pointer of type char named cleanString and newLineString. It returns a bool value.

	bool isValid = true;											// this variable will be used to check if input is valid

	for (int i = 0; i < strlen(x) && isValid; i++) {				// if i is less than the length of string x and isValid is true then this loop continues executing

		if ((x[i] >= ASCIIZERO && x[i] <= ASCIININE) || x[0] == ASCIIMINUS) {		// if the string is between 0 and 9 or the first element of the string is '-', then this if block gets executed

			isValid = true;															// isValid is set to true 
		}
		else {																	// if the input is not between 0 and 9 then this else block gets executed

			isValid = false;												// isValid variable is set to false
		}
	}

	for (int j = 0; j < strlen(y) && isValid; j++) {								// the same thing is done here for value of y

		if ((y[j] >= ASCIIZERO && y[j] <= ASCIININE) || y[0] == ASCIIMINUS) {

			isValid = true;
		}
		else {

			isValid = false;
		}
	}

	return isValid;						// returning isValid variable
}
