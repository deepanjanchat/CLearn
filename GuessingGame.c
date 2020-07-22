/*
 * GuessingGame.c
 *
 *  Created on: 21-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int main()
{
	int expValue, dice1, dice2, total;
	char response;
	srand(time(NULL));
	do{
		do{
			printf("Enter the expected sum of 2 dice rolls:\t");
			scanf(" %d", &expValue);
		} while(expValue<0||expValue>12);
		dice1 = (rand()%5)+1;
		dice2 = (rand()%5)+1;
		total = dice1 + dice2;
		printf("Dice 1 was rolled and the value was %d\n", dice1);
		printf("Dice 2 was rolled and the value was %d\n", dice2);
		printf("\nThe total rolled value was %d", total);
		if((total>expValue)||(total<expValue)){
			printf("\nYou missed by %d!\n", abs(total-expValue));
		}
		if(total==expValue){
			printf("\nCongratulations! You are right on target!\n");
		}
		printf("Would you like to play again? Answer Y or N:\t");
		scanf(" %c", &response);
	} while(toupper(response)=='Y');
}
