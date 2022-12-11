#pragma once

#include <stdio.h>
#include "Task.h"

typedef struct taskNode
{
	TASK nodeData;
	struct taskNode* next;
}TASK_NODE, * P_TASK_NODE;

void SearchForAppointment(P_TASK_NODE, char*);