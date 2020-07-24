/*
 * ComplexMovieReview.c
 * Trying the movie review program with fgets. Ask user for a bunch of movies, get ratings, sort the ratings, show the sorted list.
 *  Created on: 24-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define YEAR 2020
int main()
{
	char *movies[20];
	int ratings[20];
	int i, ans;
	printf("How many movies did you watch in %d:\t", YEAR);
	scanf(" %d", &ans);
	for(i=0;i<ans;i++){
		printf("Provide the movie name:\t");
		scanf(" %s",movies[i]);
		printf("Provide the rating (between 1-10):\t");
		scanf(" %d", &ratings[i]);
	}
	for(i=0;i<ans;i++){
	printf("%s\n",movies[i]);
	}
}

