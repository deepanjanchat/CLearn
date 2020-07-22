/*
 * BBStats.c
 * this program has three arrays: one for scoring, one for rebounding, and one for assists.
 * The program searches through the scoring totals, finds the game in which the player scored the most points,
 * and then prints the player’s total in all three categories in that particular game:
 *
 *  Created on: 22-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
int main()
{
	int score[7] = {35, 25, 40, 22, 43, 21, 42};
	int rebound[7] = {6, 19, 21, 23, 6, 12, 9};
	int assist[7] = {12, 17, 9, 12, 18, 16, 5};
	int i, maxScore = 0, bestGame, total;
	for(i=0;i<7;i++){
		if(score[i]>maxScore){
			maxScore = score[i];
			bestGame = i;
		}
	}
	total = score[bestGame]+rebound[bestGame]+assist[bestGame];
	printf("The best game was %d\n", bestGame+1);
	printf("The total score was %d\n", total);
}

