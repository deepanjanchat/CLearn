/*
 * AskMultiply.c
 *
 *  Created on: 17-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#include <string.h>
int main()
{
	int num1, num2, product;
	char repeat;
	do {
		printf("Provide a number:\t");
		scanf(" %d", &num1);
		printf("Provide another number:\t");
		scanf(" %d", &num2);
		product = num1*num2;
		printf("\nThe multiplication result is %d", product);
		printf("\nWould you like to repeat? Y/N:\t");
		scanf(" %c", &repeat);
	} while(repeat=='Y'||repeat=='y');
	return 0;
}
