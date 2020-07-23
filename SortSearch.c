/*
 * SortSearch.c
 * Create linked arrays for cust ID and balances. Sort both.
 * Search for a cust ID and find linked balance.
 * If balance > $100, don't give credit.
 *  Created on: 23-Jul-2020
 *      Author: dc
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	int custID[6] = {381, 786, 564, 809, 467, 340};
	float bal[6] = {76.2, 67.9, 656.9, 34.1, 787.1, 78};
	int i, inner, outer, tempCust, checkID, found = 0;
	float tempBal;
	for(outer=0;outer<5;outer++){
		for(inner=outer+1;inner<6;inner++){
			if(custID[inner]<custID[outer]){
				tempCust = custID[outer];
				tempBal=bal[outer];
				custID[outer]=custID[inner];
				bal[outer]=bal[inner];
				custID[inner]=tempCust;
				bal[inner]=tempBal;
			}
		}
	}
	printf("Enter a Customer ID for which you would like to know the balance:\t");
	scanf(" %d", &checkID);
	for(i=0;i<6;i++){
		if(custID[i]==checkID){
			found =1;
			printf("The balance for customer %d is %.2f\n", custID[i], bal[i]);
			if(bal[i]>100.00){
				printf("No more credit for this customer!");
			}
			else printf("This customer can be given more credit.\n");
		}
		if(custID[i]>checkID){
			break;
		}
	}
	if(found==0){
		printf("This customer %d was not found.\n", checkID);
	}
}
