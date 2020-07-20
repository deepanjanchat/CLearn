/*
 * SchoolStuff.c
 *
 *  Created on: 14-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#define COSTPENCIL 0.23
#define COSTNOTEBK 2.89
#define COSTLUNCHBX 4.99
int main()
{
	char firstName[25], lastName[25];
	int numPencils, numNoteBooks, day, month, year;
	int numLunchBox = 1;
	float costTotal;
	printf("Enter your first name:\t");
	scanf(" %s", firstName);
	printf("Enter your last name:\t");
	scanf(" %s", lastName);
	printf("How many pencils do you need?\t");
	scanf(" %d", &numPencils);
	printf("How many notebooks do you need?\t");
	scanf(" %d", &numNoteBooks);
	printf("By when do you need these? Please enter in mm/dd/yy format.\t");
	scanf(" %d/%d/%d", &month, &day, &year);
	costTotal = numPencils*COSTPENCIL + numNoteBooks*COSTNOTEBK + numLunchBox*COSTLUNCHBX;
	printf("The total cost for student %s %s is %.2f. It will be delivered on %d/%d/%d.\n", firstName, lastName, costTotal, month, day, year);
}
