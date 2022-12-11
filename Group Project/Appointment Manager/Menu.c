
#include "Menu.h"

void DisplayMenu(void)
{
	fputs(" Welcome to Appointment Manager Menu!\n\n", stdout);
	fputs(" a) Add a new appointment\n", stdout);
	fputs(" b) Delete an existing appointment\n", stdout);
	fputs(" c) Update an existing appointment\n", stdout);
	fputs(" d) Display a single appointment\n", stdout);
	fputs(" e) Display a range appointment\n", stdout);
	fputs(" f) Display all appointment\n", stdout);
	fputs(" g) Search for an appointment\n", stdout);
	fputs(" h) Quit\n\n", stdout);
	fputs(" Please choose one of the following option from a to h\n", stdout);
	fputs(" Option: ", stdout);
}