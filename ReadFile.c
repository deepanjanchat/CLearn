/*
 * ReadFile.c
 * Read an existing file from disk.
 *  Created on: 03-Aug-2020
 *      Author: dc
 */
#include <stdio.h>
#include <stdlib.h>
FILE *fptr;
int main(void){
	char buffer[100];
	fptr = fopen("\\users\\dc\\Desktop\\BuildStuff\\eclipse-workspace\\CLearner\\BookInfo.txt", "r");
	if(fptr!=0){
		while(!feof(fptr)){
			fgets(buffer, sizeof(buffer), fptr);
			puts(buffer);
		}
	}
	else printf("Error opening file!\n");
	fclose(fptr);
}
