/*
 * runoff.c
 * Pseudocode
 * Func vote to capture the ranked votes from each voter - DONE
 * 	Check whether the name matches that of a candidate (return true or false accordingly)
 * 	Update the pref array with the index number of the candidate (since pref is an int array)
 * 	Initialises the pref array
 *
 * Once all the votes are done...
 * Func tabulate to score the candidates - DONE
 * 	Update most preferred candidate in the pref array if any eliminations have happened
 * 	Update the votes in candidates struct, based on the pref array. See where the candidate was 1st pref ([i][0])
 * Func print winner
 * 	Check the total votes against each candidate
 * 	Check if any candidate has reached majority - round(voter_count/2) or voter_count/2 + 1
 * 	Then print the winner
 * 	If there are multiple candidates that have reached majority and have the same number of votes
 * 	Then print the winners in new lines
 * 	If no candidates have reached majority, then - Return False
 * Func find min - DONE
 * 	Check who has the min number of votes among the non-eliminated candidates in the candidates struct
 * 	Return the min votes - linear search? Or sort? Search may be better since there are multiple parameters (elim flag)
 * Tie func - DONE
 * 	Check candidate struct to see whether all non-eliminated candidate have th min vote
 * 	Return True. Else false.
 * Eliminate func - DONE
 * Eliminate candidates that have the number of votes passed by calling function.
 * Update the eliminated flag in candidates struct.
 * For the eliminated candidate -
 * 	check which voters gave them highest preference (from pref array [i][0])
 * 	Check who is the next preferred candidate for these voters (pref array [i][1])
 *
 * 	Addition printf (commented out) were added to test
 *
 *  Created on: 21-Aug-2020
 *      Author: dc
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // search for passed name against the candidates list and update the preferences array
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i; //indicate which candidate the voter voted for
            return true;
        }
    }
    /*for (int j = 0; j < candidate_count; j++)
    {
        printf("%s, %d\n", candidates[j].name, candidates[j].votes);
    }
    for (int p = 0; p < voter_count; p++)
    {
        for (int q = 0; q < candidate_count; q++)
        {
            printf("Voter %d, pref %d, candidate %d\n", p+1, q+1, preferences[p][q]);
        }
    }*/
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //tabulate who has the max preferred votes based on the preferences array
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == true)
        {
            for (int j = 0; j < voter_count; j++) //this loop transfers the votes to the next preferred non-eliminated candidate
            {
                if (preferences[j][0] == i) //check whether the eliminated candidate was most preferred by any voter
                {
                    for (int p = 1; p < candidate_count; p++)
                    {
                        if (candidates[preferences[j][p]].eliminated == false) //find the next most preferred candidate
                        {
                            preferences[j][0] = preferences[j][p]; //update the voter's most preferred candidate
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < voter_count; i++)
    {
        candidates[preferences[i][0]].votes++;
    }
    /*for (int a = 0; a < candidate_count; a++)
    {
        printf("%s, %d\n", candidates[a].name, candidates[a].votes);
    }
    for (int p = 0; p < voter_count; p++)
    {
        for (int q = 0; q < candidate_count; q++)
        {
            printf("Voter %d, pref %d, candidate %d\n", p+1, q+1, preferences[p][q]);
        }
    }*/
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int max = 0, maj = 0, ctr = 0;
    if ((voter_count % 2) == 1) //calculate the min vote needed to win
    {
        maj = (int)(voter_count / 2) + 1;
    }
    else
    {
        maj = (voter_count / 2) + 1;
    }
    //printf("Majority Reqd: %d\n", maj);
    for (int i = 0; i < candidate_count; i++) //find non-eliminated candidate with max vote
    {
        if (candidates[i].eliminated == false) //check only non-eliminated candidates
        {
            if (candidates[i].votes > max)
            {
                max = candidates[i].votes; //identify max votes won by any candidate
            }
        }
    }
    //printf("Max Vote %d\n", max);
    if (max >= maj) //check if the votes have reached the majority mark
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[j].eliminated == false && candidates[j].votes == max) //check if multiple candidates have the same max votes
            {
                printf("%s\n", candidates[j].name); //print candidate name
            }
        }
        return true;
    }
    return false;
}

// Return the minimum number of votes any non-eliminated candidate has
int find_min(void)
{
    int min = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes < min)
            {
                min = candidates[i].votes; //linear search since each vote count has to be considered
            }
        }
    }
    //printf("Min votes %d\n", min);
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int ctr1 = 0, ctr2 = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if ((candidates[i].eliminated == false)
            && (candidates[i].votes == min)) //this loop finds how many non-eliminated candidates have the min vote
        {
            ctr1++;
        }
        if (candidates[i].eliminated == true) //this loop finds how many candidates have already been eliminated
        {
            ctr2++;
        }
    }
    //printf("Nbr of candidates with min vote %d\n", ctr1);
    if (ctr1 + ctr2 == candidate_count) //checks if all non-eliminated candidates have the min vote
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    int ctr = 0, n = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if ((candidates[i].eliminated == false)
            && (candidates[i].votes == min)) //this loop finds any non-eliminated candidates that have the min vote
        {
            candidates[i].eliminated = true; //eliminates the candidates with min votes
        }
    }
    /*for (int a = 0; a < candidate_count; a++)
    {
        printf("%s, %d\n", candidates[a].name, candidates[a].votes);
    }
    for (int b = 0; b < voter_count; b++)
    {
        for (int c = 0; c < candidate_count; c++)
        {
            printf("Voter %d, pref %d, candidate %d\n", b+1, c+1, preferences[b][c]);
        }
    }*/
    return;
}
