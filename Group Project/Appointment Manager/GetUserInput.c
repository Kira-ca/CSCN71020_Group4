#include "GetUserInput.h"
#include "StringUtils.h"
#include "Task.h"

void GetUserInput(char* userInputBuffer)
{
	fgets(userInputBuffer, MAXSTRLEN, stdin);

	CleanNewLineFromString(userInputBuffer);
}