/*
 * plurality.c
 * Ask the user to enter a list of election candidates, and number of voters
 * Ask for vote. Wrong candidate name will result in invalid vote
 * Calculate the total votes per candidate and print result
 * If multiple candidates get the same number of votes, print them all
 *  Created on: 17-Aug-2020
 *      Author: dc
 */
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name); //CS50 header data type
void print_winner(void);

int main(int argc, string argv[]) //CS50 header data type
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // search for passed name against the candidate list and update vote count
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Identify the max voter count
    // Sort the candidate list using bubble sort so last element has the max votes
    int ctr = -1; //set an initial non-zero value for swap counter
    while (ctr != 0) //repeat until no swaps
    {
        ctr = 0; //set swap counter to zero
        for (int i = 0; i < candidate_count - 1; i++)
        {
            if (candidates[i].votes > candidates[i + 1].votes) //Compare each pair and swap if they are not in order
            {
                int temp = candidates[i].votes;
                string tempName = candidates[i].name;
                candidates[i].votes = candidates[i + 1].votes;
                candidates[i].name = candidates[i + 1].name;
                candidates[i + 1].votes = temp;
                candidates[i + 1].name = tempName;
                ctr++; //increment the counter
            }
        }
    }
    printf("%s\n", candidates[candidate_count - 1].name); //print the name of the candidate who has the max votes
    for (int i = candidate_count - 2; i >= 0; i--) //test whether multiple candidates have the same number of votes
    {
        if (candidates[i].votes == candidates[candidate_count - 1].votes) //test whether any other candidate has the same vote count
        {
            printf("%s\n", candidates[i].name); //print that candidates name
        }
    }
    return;
}

