/*
 * caesar.c
 * Ask for a non-negative integer (key) as command line argument while running the program
 * Return 1 from main and re-prompt if input is something else - like string, or multiple numbers
 * Do not assume that the number will be within 1 and 26.
 * Ask user for plaintext - this will be a string
 * Rotate each alphabet by the key - separately for upper case and lower case
 * No changes to non-alphabets
 *  Created on: 17-Aug-2020
 *      Author: dc
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h> //CS50 header
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc != 2) //check that only 2 args are passed
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) != 0) //check that second arg is a number
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
    }
    int key = (atoi(argv[1])) % 26; //convert the key string to an int
    string plain = get_string("Plaintext: "); //user inputs plain text, uses a CS50 header function and data type
    string code = plain;
    int len = strlen(plain);
    for (int i = 0; i < len; i++)
    {
        if (islower(plain[i]) != 0)
        {
            code[i] = plain[i] + key - 26; //ensures that the ascii doesn't cross that of regular ascii
            if (code[i] < 97) //checks if ascii is now lower than 'a'
            {
                code[i] += 26; //brings it back into a-z
            }
        }
        else if (isupper(plain[i]) != 0)
        {
            code[i] = plain[i] + key - 26; //ensures that the ascii doesn't cross Z
            if (code[i] < 65) //checks is ascii is lower than A
            {
                code[i] += 26; //brings it back into A-Z
            }
        }
        else
        {
            code[i] = plain[i]; //no impact for non-alphabets
        }
    }
    printf("ciphertext: %s\n", code);
}

