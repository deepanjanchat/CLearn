/*
 * SimpleStruct.c
 * Creating a simple structure by allocating memory in the heap.
 * Ask user how many books to store, allocate memory, ask for details, display details.
 *  Created on: 30-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct bookInv {      //common coding practice is to save structure definitions in a separate header file.
	char title[30];
	char author[30];
	int pages;
	float price;
};
int main(void)
{
	int num;
	printf("How many books would you like to provide the details for?\t");
	scanf(" %d", &num);
	getchar(); //to handle the trailing \n character from scanf so that fgets works.
	struct bookInv *books[num];
	for(int i=0; i<num; i++) //allocate heap memory based on the number of books to be stored
		{
			books[i] = (struct bookInv *) malloc(sizeof(struct bookInv));
			printf("\nWhat is the name of this book?\t");
			fgets(books[i]->title, sizeof(books[i]->title), stdin);
			printf("\nWho is the author?\t");
			fgets(books[i]->author, sizeof(books[i]->author), stdin);
			printf("\nHow many pages does the book have?\t");
			scanf(" %d", &books[i]->pages);
			printf("\nWhat is the price?\t$");
			scanf(" %f", &books[i]->price);
			getchar(); //to handle the trailing \n from the scanf so fgets works in the next loop.
		}
	printf("Here is the collection of books -\n");
	for(int i=0; i<num; i++)
		{
			printf("Title - %s\n", books[i]->title); //additional newline created due to fgets. Multiple threads exist on how to resolve that.
			printf("Author - %s\n", books[i]->author); // additional newline created due to fgets.
			printf("Pages - %d\n", books[i]->pages);
			printf("Price - $%.2f\n", books[i]->price);
			printf("\n");
		}
	free(books[num]); //program executes fine, but get an abort 6 error while freeing memory.
}
