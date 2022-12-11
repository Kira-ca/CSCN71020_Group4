
#include "Task.h"
#include "TaskNode.h"
#include <string.h>
#include <stdlib.h>

void AddAppointment(P_TASK_NODE task)
{
	/// Allocate Space in memory the struct

	// Search 


}


void SearchForAppointment(P_TASK_NODE task, char* keyword)
{
	if (task == NULL)
	{
		puts(" Task is empty. No appointment to search!");
		exit(EXIT_FAILURE);
	}

	P_TASK_NODE currentTask = task;

	if (strcmp(currentTask->nodeData.lastName, keyword) == 0)
	{
		if (currentTask->next != NULL)
		{
			task = currentTask->next;
		}
		else
		{

		}
	}
	{

	}

}