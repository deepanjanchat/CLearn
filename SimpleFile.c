/*
 * SimpleFile.c
 * Enter details of books that are then saved to a file
 *  Created on: 03-Aug-2020
 *      Author: dc
 */
#include <stdio.h>
#include <stdlib.h>
#include "BookInv.h"
FILE *fptr;
int main(void)
{
struct bookInv books[3];
for(int i=0; i<3; i++)
	{
		printf("\nWhat is the name of this book?\t");
		fgets(books[i].title, 30, stdin);
		printf("\nWho is the author?\t");
		fgets(books[i].author, 30, stdin);
		printf("\nHow many pages does the book have?\t");
		scanf(" %d", &books[i].pages);
		printf("\nWhat is the price?\t$");
		scanf(" %f", &books[i].price);
		getchar();
	}
fptr = fopen("\\users\\dc\\Desktop\\BuildStuff\\eclipse-workspace\\CLearner\\BookInfo.txt", "w");
if(fptr==0)
	{
		printf("The file could not be opened!\n");
		exit(1);
	}
fprintf(fptr, "Here is the collection of books - \n");
for(int i=0; i<3; i++)
	{
		fprintf(fptr, "Title - %s\n", books[i].title);
		fprintf(fptr, "Author - %s\n", books[i].author);
		fprintf(fptr, "Pages - %d\n", books[i].pages);
		fprintf(fptr, "Price - $%.2f\n", books[i].price);
		fprintf(fptr, "\n\n");
	}
fclose(fptr);
}

