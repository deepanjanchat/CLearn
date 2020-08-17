/*
 * readability.c
 * index = 0.0588 * L - 0.296 * S - 15.8
 * L is the average number of letters per 100 words in the text
 * S is the average number of sentences per 100 words in the text
 * Ask user to input a string, count the number of letters (a-z, A-Z)
 * Calculate grade
 * Print as output "Grade X" where X is the grade level
 *
 *  Created on: 17-Aug-2020
 *      Author: dc
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h> //CS50 header
#include <math.h>

int letterCount(string text); //func to count letters
int wordCount(string text); //func to count words
int senCount(string text); //func to count sentences

int main(void)
{
    string input = get_string("Text: "); //text to be graded
    int letters = letterCount(input);
    int words = wordCount(input);
    int sen = senCount(input);
    int l = (letters * 100) / words; //calculate letters per 100 words
    int s = (sen * 100) / words; //calculate sentences per 100 words
    int grade = round(0.0588 * l - 0.296 * s - 15.8); //calculate grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

int letterCount(string text)
{
    int ctr = 0, len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]) != 0) //count the alphabets
        {
            ctr++;
        }
    }
    return ctr;
}

int wordCount(string text)
{
    int ctr = 1, len = strlen(text); //ctr set at 1 coz 1 word will have 0 space, 2 words will have 1 space
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ') //assuming words are separated by space only
        {
            ctr++;
        }
    }
    return ctr;
}

int senCount(string text)
{
    int ctr = 0, len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') //assuming these are the sentence terminators
        {
            ctr++;
        }
    }
    return ctr;
}

