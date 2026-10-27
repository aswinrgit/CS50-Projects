#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
    int strength;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count = 0;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(int voter_count);
void sort_pairs(void);
void lock_pairs(int voter_count);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs(voter_count);
    sort_pairs();
    lock_pairs(voter_count);
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    int flag = 0;
    for ( int i =0; i < candidate_count ; i++)
    {
        if(strcmp(candidates[i], name) == 0)
        {
            ranks[i] = rank;
            flag++;
        }
    }
    if(flag == 0)
    return false;
    else
    return true;

}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{


    int position[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(j == ranks[i])
            {
                position[j] = i;
            }
        }
    }


    for(int i =0; i < candidate_count ; i++)
    {
        for(int j = 0; j < candidate_count ; j++)
        {

             if(ranks[i] < ranks[j])
            {
                preferences[i][j]++;

            }
             else if(i == j)
            {
                continue;
            }

        }
    }
     for(int i =0; i < candidate_count ; i++)
    {
        for(int j = 0; j < candidate_count ; j++)
        {
            // printf("%i",preferences[i][j]);
        }
        // printf("\n");
    }


}

// Record pairs of candidates where one is preferred over the other
void add_pairs(int voter_count)
{
    for(int i =0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(i == j)
            {
                continue;
            }
            else if (preferences[i][j] > voter_count/2)
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;

                pairs[pair_count].strength = preferences[i][j] - preferences[j][i];
                pair_count++;
            }
        }
    }
    for (int i = 0; i < pair_count; i++)
    {
        // printf("%i %i %i\n", pairs[i].winner, pairs[i].loser, pairs[i].strength);
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        for(int j = 0; j < pair_count - i - 1; j++)
        {
            if(pairs[j].strength < pairs[j+1].strength)
        {
            pair replace_pair;
            replace_pair = pairs[j+1];
            pairs[j+1] = pairs[j];
            pairs[j] = replace_pair;

        }

        }


    }
    // printf("\n");
    for (int i = 0; i < pair_count; i++)
    {
        // printf("%i %i %i\n", pairs[i].winner, pairs[i].loser, pairs[i].strength);
    }
    return;
}
// Recursive function to check if entry makes a circle
bool makes_circle(int cycle_start, int loser)
{
    if (loser == cycle_start)
    {
        // If the current loser is the cycle start
        // The entry makes a circle
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (makes_circle(cycle_start, i))
            {
                // Forward progress through the circle
                return true;
            }
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(int voter_count)
{
      for (int i = 0; i < pair_count; i++)
    {
        if (!makes_circle(pairs[i].winner, pairs[i].loser))
        {
            // Lock the pair unless it makes a circle
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int winner_count[candidate_count];
    for (int i = 0, flag = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(locked[i][j])
            {
                flag++;

            }

        }
        winner_count[i] = flag;
        // printf("%i\n", flag);
        flag = 0;
    }

    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count - i - 1; j++)
        {
            if(winner_count[j] > winner_count[j+1])
            {
                int swap;
                swap = winner_count[j+1];
                winner_count[j+1] = winner_count[j];
                winner_count[j] = swap;
            }
        }
    }
    printf("The winner is : %s\n", candidates[winner_count[0]]);
    return;
}
