/*
 * CardBinCheck.c
 * When a number is entered, tell whether this is a valid card number. Also identify the card brand.
 * This program implements Luhn's checksum algo as a function
 * This program implements functions to get length of a num and any digit of a given number
 * The card brand identification is based on rules provided in CS50. They can be enhanced if needed.
 *  Created on: 04-Aug-2020
 *      Author: dc
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getLength(long num);
int getDigit(long num, int n);
int luhnAlgo(long num);
int main(void)
{
    long num, prodSum = 0, sum = 0;
    int len, firDig, secDig, value;
    do
    {
        printf("Enter a card number:\t");
        scanf(" %ld", &num);
    } while (num < 0); //wont accept negative numbers
    len = getLength(num); //calls the function to get length
    firDig = getDigit(num, 1);
    secDig = getDigit(num, 2);
    value = luhnAlgo(num);
    //loop to identify card type
    if (value != 0)
    {
        printf("INVALID\n");
    }
    if (value == 0)
    {
        if (len == 15 && (firDig == 3) && ((secDig == 4) || (secDig == 7)))
        {
            printf("AMEX\n");
        }
        else if (len == 16 && (firDig == 5) && ((secDig == 1) || (secDig == 2) || (secDig == 3) || (secDig == 4) || (secDig == 5)))
        {
            printf("MASTERCARD\n");
        }
        else if (((len == 13) || (len == 16)) && (firDig == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

int getLength(long num){
	int len = 0;
	while(num > 0){
		++len;
	    num /= 10;
	}
	return len;
}

int getDigit(long num, int n){
	int len, value = 0;
	len = getLength(num);
	long a = 0, b = 0;
	a = (long)pow(10, (double)(len - n));
	b = num / a;
	value = b % 10;
	return value;
}

int luhnAlgo(long num){
	int prodSum = 0, value = 0, sum = 0;
	int len = getLength(num);
	for (double i = 1; i < len; i += 2){
		long a = 0, b = 0, tempNum = num;
		a = tempNum / ((long) pow(10, i));
		b = (a % 10) * 2;
	    if (b > 9){
	    	b = b - 9;
	    }
	    prodSum += b;
	}
	for (double i = 0; i < len; i += 2){
		long a = 0, b = 0, tempNum = num;
		a = tempNum / ((long) pow(10, i));
	    b = a % 10;
	    sum += b;
	    }
	value = (prodSum + sum) % 10;
	return value;
}




