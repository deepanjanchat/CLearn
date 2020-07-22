/*
 * BBStats.c
 * this program has three arrays: one for scoring, one for rebounding, and one for assists.
 * These are filled with random numbers from 1 to 75.
 * The program searches through the scoring totals, finds the game in which the player scored the most points,
 * and then prints the player’s total in all three categories in that particular game:
 *
 *  Created on: 22-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int games, score[10], rebound[10], assist[10];
	int i, maxScore = 0, bestGame, total;
	srand(time(NULL));
	printf("How many games were played? Enter any value up to 10.\n");
	scanf(" %d", &games);
	for(i=0;i<games;i++){
		score[i] = (rand()%74)+1;
		rebound[i] = (rand()%74)+1;
		assist[i] = (rand()%74)+1;
	}
	printf("These are the scores:\n");
	for(i=0;i<games;i++){
		printf("For game %d, score was %d\n", i+1, score[i]);
	}
	printf("These are the rebounds:\n");
	for(i=0;i<games;i++){
		printf("For game %d, rebounds collected were %d\n", i+1, rebound[i]);
	}
	printf("These are the assists:\n");
	for(i=0;i<games;i++){
		printf("For game %d, assists were %d\n", i+1, assist[i]);
	}
	for(i=0;i<games;i++){
		if(score[i]>maxScore){
			maxScore = score[i];
			bestGame = i;
		}
	}
	total = score[bestGame]+rebound[bestGame]+assist[bestGame];
	printf("The best game was %d\n", bestGame+1);
	printf("The total score was %d\n", total);
}

