/*
 * Counter.c
 *
 *  Created on: 17-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#define COUNT 5
int main()
{
	int ctr = 0;
	while (ctr<COUNT)
	{
		printf("The count is at %d\n",++ctr);
	}
	while (ctr>1)
	{
		printf("The count is at %d\n",--ctr);
	}
}
