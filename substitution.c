/*
 * substitution.c
 * Convert a plain text into cipher text using a key entered as command line input.
 * Check that the key has 26 alphabets, no alphabet repeating.
 * Give error message if key <26, non-alphabets, no command line input, multiple inputs
 *  Created on: 17-Aug-2020
 *      Author: dc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h> //CS50 header
int main(int argc, char *argv[])
{
    if (argc != 2) //ensure 2 arguments are entered
    {
        printf("Usage: ./substitution key\n");
        exit(1);
    }
    if (argc == 2)
    {
        int len = strlen(argv[1]);
        if (len != 26) //tests whether length of key is 26
        {
            printf("Key must contain 26 characters.\n");
            exit(1);
        }
        if (len == 26)
        {
            for (int i = 0; i < len; i++)
            {
                if (isalpha(argv[1][i]) == 0) //tests that only alphabets are entered in the key
                {
                    printf("The key must contain only alphabets.\n");
                    exit(1);
                }
            }
            for (int i = 0; i < len; i++) //matches each char to the remaining char on the right to find a match. Exits if there is a match.
            {
                for (int j = i + 1; j < len; j++)
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        printf("No alphabet can repeat in the key.\n");
                        exit(1);
                    }
                }
            }
        }
    }
    string plain = get_string("plaintext: "); //user enters plain text, this uses a pre-built function from CS50 header
    int len = strlen(plain);
    char ciph[len];
    for (int i = 0; i < len; i++)
    {
        if (plain[i] == '\0')
        {
            break;
        }
        if (isalpha(plain[i]) == 0) //handling non-alphabet characters in the plain text
        {
            ciph[i] = plain[i];
        }
        if (isupper(plain[i]) != 0) //handling upper case
        {
            int loc = (int)(plain[i] - 'A'); //provides position of the entered alphabet in the english alphabet
            ciph[i] = toupper(argv[1][loc]); //finds the alphabet in the key at that position, converts it to upper case, copies it
        }
        if (islower(plain[i]) != 0)
        {
            int loc = (int)(plain[i] - 'a'); //provides position of the entered alphabet in the english alphabet
            ciph[i] = tolower(argv[1][loc]); //finds the alphabet in the key at that position, converts it to lower case, copies it
        }
    }
    char cipher[len];
    for (int i = 0; i < len; i++) //to remove any junk values getting added during the above loop
    {
        cipher[i] = ciph[i];
    }
    printf("ciphertext: %s\n", cipher);
    return 0;
}

