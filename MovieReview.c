/*
 * MovieReview.c
 *
 *  Created on: 17-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#include <string.h>
#define YEAR 2020
int main()
{
	int count, i, rating;
	int maxRating=0, minRating=10;
	char favMovie[40], badMovie[40], movieName[40];
	do{
		printf("\nHow many movies have you seen in %d?\t", YEAR);
		scanf(" %d", &count);
		if(count<1){
		printf("Enter at least 1 movie name!\n");
		}
	} while(count<1);
	for(i=0;i<count;i++)
	{
		printf("Provide the movie name:\t");
		scanf(" %s", movieName);
		printf("Provide the rating between 1 and 10:\t");
		scanf(" %d", &rating);
		if(rating>maxRating)
		{
			maxRating = rating;
			strcpy(favMovie, movieName);
		}
		if(rating<minRating)
		{
			minRating = rating;
			strcpy(badMovie, movieName);
		}
	}
	printf("Your fave movie is %s and its rating is %d\n", favMovie, maxRating);
	printf("Your least fave movie is %s and its rating is %d\n", badMovie, minRating);
}
