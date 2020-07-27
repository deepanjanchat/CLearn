/*
 * SortRandom.c
 * Ask the user to select how many numbers are to be sorted, generate that many random numbers, find smallest and biggest values, find avg
 *  Created on: 27-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	int sort, i, max, smallest, biggest = 0, total = 0;
	float avg;
	int *random;
	printf("How many numbers would you like to sort?\t");
	scanf(" %d", &sort);
	printf("What should be the maximum value?\t");
	scanf(" %d", &max);
	smallest = max;
	random = (int *) malloc(sort*sizeof(int));
	if(!random){
		printf("No memory available!\n");
	}
	for(i=0;i<sort;i++){
		random[i] = (rand()%max)+1;
	}
	for(i=0;i<sort;i++){
		total+=random[i];
		if(random[i]>biggest){
			biggest = random[i];
		}
		if(random[i]<smallest){
			smallest = random[i];
		}
	}
	avg = ((float)total/(float)max);
	printf("\nThe biggest nnumber is: %d", biggest);
	printf("\nThe smallest number is: %d", smallest);
	printf("\nThe average value is: %.2f", avg);
	printf("\nThe total value is: %d\n", total);
	free(random);
}
