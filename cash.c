/*
 * cash.c
 *
 *  Created on: 03-Aug-2020
 *      Author: dc
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
int main(void)
{
    float amt;
    do
    {
        printf("Please enter the amount for which you need change:\t");
        scanf(" %f", &amt);
    } while ((amt < 0) || (isdigit(amt)!=0)); //check for a non-negative input
    int total = round(amt * 100);
    int a = abs(total / 25); //# of 25c coins
    int z = total % 25; //what to send to the next part
    int b = abs(z / 10); //# of 10c coins
    int y = z % 10; //what to be sent to the next part
    int c = abs(y / 5); //# of 5c coins
    int d = y % 5; //# of 1c coins
    printf("total number of coins: %d\n", a + b + c + d);
}

