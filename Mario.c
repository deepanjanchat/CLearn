/*
 * Mario.c
 * Week 1 in CS50. The harder Mario program to build a pyramid.
 *  Created on: 03-Aug-2020
 *      Author: dc
 */
#include <stdio.h>
//#include <cs50.h>
int main(void)
{
    int num, h, v;
    do
    {
        printf("Please enter the height of the pyramid (any number between 1-8): ");
        scanf(" %d", &num);
    }
    while (num < 1 || num > 8); //this checks for the validity of the input
    for (v = 1; v <= num; v++) //this helps count the vertical height
    {
        for (h = 0; h < num-v; h++) //this helps count the spaces in each line
        {
            printf(" ");
        }
        for (h = num-v; h < num; h++) //this helps count the number of # in each line
        {
            printf("#");
        }
        printf("  "); //this puts in 2 spaces in each line
        for (h = num-v; h < num; h++) //this helps count the second set of # in each line
        {
            printf("#");
        }
        printf("\n"); //this is required to start a new line
    }
}
