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
	char movie1[40], movie2[40], movie3[40], movie4[40], movie5[40];
	char *movies[5] = {movie1, movie2, movie3, movie4, movie5};
	int ratings[5];
	int i, ans;
	printf("How many movies did you watch in %d: (anywhere between 1-5)\t", YEAR);
	scanf(" %d", &ans);
	getchar(); //handle the newline from above scanf. Adds a trailing \n to the movie entry. getch() would have solved it, but not available as standard.
	for(i=0;i<ans;i++){
		printf("Provide the movie name:\t");
		fgets(movies[i], 41, stdin); //this doesn't execute unless the trailing newline character from previous scanf is handled
		printf("Provide the rating (between 1-10):\t");
		scanf(" %d", &ratings[i]);
		getchar(); //handle the newline from above scanf.
	}
	for(i=0;i<ans;i++){
	printf("%s\n",movies[i]);
	}
}
