
#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "Task.h"
#include "TaskADT.h"
#include "TaskNode.h"
#include "GetUserInput.h"

int main(void)
{
	P_TASK_NODE task = NULL;

	int ch = 0;
	char searchKeywordBuffer[MAXSTRLEN];
	char userInputBuffer[MAXSTRLEN];

	while (ch != 'h')
	{
		DisplayMenu();
		if ((ch = getchar()) != '\n')
			while (getchar() != '\n') continue;

		switch (ch)
		{
		
		case 'a':
			// a) add a new appt
			break;

		case 'b':
			// b) delete an existing appt
			break;

		case 'c':
			// c) update an existing appt
			break;

		case'd':
			// d) display single appt
			break;

		case 'e':
			// e) display range appt
			break;

		case 'f':
			// f) display all appt
			break;

		case 'g':
			puts(" Which appointment would you like to search? ");
			printf(" Search For: ");
			GetUserInput(searchKeywordBuffer);
			SearchForAppointment(task, searchKeywordBuffer);
			// g) search for appt
			break;

		case 'h':
			// e) Quit
			break;
		default:
			break;
		}
	}


	return 0;
}