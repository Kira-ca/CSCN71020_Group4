#pragma once

#define MAXSTRLEN 50

typedef enum PriorityLevel { Low, Moderate, High } PRIORITYLEVEL;

typedef struct task
{
	char firstName[MAXSTRLEN];
	char lastName[MAXSTRLEN];
	int day;
	int month;
	int year;
	PRIORITYLEVEL priorityLevel;
}TASK, *P_TASK;


void AddAppointment(P_TASK_NODE);

void SearchForAppointment(P_TASK_NODE, char*);