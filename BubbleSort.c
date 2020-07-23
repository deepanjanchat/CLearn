/*
 * BubbleSort.c
 * Generate a random array of 10 numbers between 0-100, and sort that using the bubble sort algo.
 * Show the sorted array.
 *  Created on: 23-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
int i, numList[10], temp, inner, outer, swap;
srand(time(NULL));
printf("This is the unsorted list...\n");
for(i=0;i<10;i++){
	numList[i] = (rand()%99)+1;
	printf("This is the unsorted element %d: %d\n", i+1, numList[i]);
}
for(outer=0;outer<9;outer++){
	for(inner=outer+1;inner<10;inner++){
		if(numList[inner]<numList[outer]){ //numList[outer]>numList[inner] will give wrong values because we are changing numList[outer] in the IF loop
			temp = numList[outer];
			numList[outer] = numList[inner];
			numList[inner] = temp;
			swap = 1;
		}
	}
}
printf("This is the sorted list...\n");
for(i=0;i<10;i++){
	printf("This is the sorted element %d: %d\n", i+1, numList[i]);
}
}
