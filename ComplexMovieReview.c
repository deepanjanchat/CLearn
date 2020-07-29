/*
 * ComplexMovieReview.c
 * Trying the movie review program with fgets. Ask user for a bunch of movies and ratings, sort the ratings, show the sorted list.
 *  Created on: 24-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define YEAR 2020
#define MAX 50
int main()
{
	char **movies; //pointer to a pointer to a char. Movies array holds the ptrs that point to the movie names.
	int *ratings;
	int i, num, inner, outer, tempRating;
	char *tempPtr;
	printf("How many movies did you watch in %d:\t", YEAR);
	scanf(" %d", &num);
	getchar(); //handle the newline from above scanf. Adds a trailing \n to the movie entry. getch() would have solved it, but not available as standard.
	movies = malloc(num*sizeof(*movies)); //this is the mem allocation for the pointers to the movie names
	ratings = (int *) malloc(num*sizeof(int));
	if(!movies||!ratings){
		printf("Not enough memory!");
	}
	for(i=0;i<num;i++){
		movies[i]=malloc(MAX*sizeof(char)); //this is the mem allocation for the movie names whose pointers are in movies array
	}
	for(i=0;i<num;i++){
		printf("Provide the movie name (max %d characters):\t", MAX);
		fgets(movies[i], MAX+1, stdin); //this doesn't execute unless the trailing newline character from previous scanf is handled
		printf("Provide the rating (between 1-10):\t");
		scanf(" %d", &ratings[i]);
		getchar(); //handle the newline from above scanf. But introduces an additional newline character after the movie name.
	}
	for(outer=0;outer<num-1;outer++){
		for(inner=outer+1;inner<num;inner++){
			if(ratings[inner]>ratings[outer]){
				tempRating = ratings[outer];
				tempPtr = movies[outer];
				ratings[outer] = ratings[inner];
				movies[outer] = movies[inner];
				ratings[inner] = tempRating;
				movies[inner] = tempPtr;
			}
		}
	}
	printf("This is the sorted list of movies and their ratings, starting with your favourite movie.\n");
	for(i=0;i<num;i++){
	printf("%s\n",movies[i]);
	printf("%d\n",ratings[i]);
	}
	free(movies);
	free(ratings);
}
