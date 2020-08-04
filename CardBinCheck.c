/*
 * CardBinCheck.c
 *
 *  Created on: 04-Aug-2020
 *      Author: dc
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    long num, prodSum = 0, sum = 0;
    int len, firDig, secDig, value;
    do
    {
        long tempNum = 0;
        len = 0;
        num = get_long("Number:");
        tempNum = num;
        while (tempNum > 0)
        {
            ++len;
            tempNum /= 10;
        } //this loop gives the lenth of the number entered
    }
    while (num < 0); //wont accept less than 13 digits or more than 16 digits or negative numbers
    //define a function to identify first digit and second digit based on length and entered number
    long x = (long)(pow(10, (double)(len - 1))); //pow accepts only double, and gives result in double
    long y = (long)(pow(10, (double)(len - 2)));
    firDig = (int)(num / x); //calculating the first digit of the card
    secDig = (int)((num / y) % 10); // calculating the second digit of the card
    //printf("%ld, %d,%d, %d\n", num, len, firDig, secDig); //test to see whether the right numbers have been calculated
    //Add a function to run Luhn's checksum
    //Loop to identify the numbers that should be multiplied by 2
    for (double i = 1; i < len; i += 2)
    {
        long a = 0, b = 0, tempNum = num;
        a = tempNum / ((long) pow(10, i));
        b = (a % 10) * 2;
        if (b > 9)
        {
            b = b - 9;
        }
        prodSum += b;
    }
    //printf("%ld\n", prodSum); //test to see whether the right numbers have been calculated
    //Loop to identify the numbers that should'nt be multiplied by 2
    for (double i = 0; i < len; i += 2)
    {
        long a = 0, b = 0, tempNum = num;
        a = tempNum / ((long) pow(10, i));
        b = a % 10;
        sum += b;
    }
    //printf("%ld\n", sum); //test to see whether the right numbers have been calculated
    value = ((int)(prodSum + sum)) % 10;  //checksum
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

