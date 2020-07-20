/*
 * AddTotal.c
 *
 *  Created on: 13-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
int main()
{
	float gift1, gift2, gift3, total;
	printf("How much would you like to spend on the gift for your wife?\n");
	scanf("%f", &gift1);
	printf("How much would you like to spend on the gift for your father?\n");
	scanf("%f", &gift2);
	printf("How much would you like to spend on the gift for your mother?\n");
	scanf("%f", &gift3);
	total = gift1+gift2+gift3;
	printf("Your total expenditure will be %.2f\n", total);
}
