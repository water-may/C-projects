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
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
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

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {  
            ranks[rank] = i;
            return true;
        }
    } 
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int a = 0;
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            if (pairs[j].winner > pairs[i].winner)
            {
                pairs[a].winner = pairs[j].winner;
                pairs[a].loser = pairs[j].loser;
                a++;
            }
        }
        
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int check = 0;
    int array[candidate_count];
    int vertical[candidate_count];
    int vcheck = 0;
    
    for (int i = 0; i <  MAX * (MAX - 1) / 2; i++)
    {
        if (pairs[i].winner == 0 & pairs[i].loser == 0)
        {
            return;
        }
        else 
        {
            
            locked[pairs[i].winner][pairs[i].loser] = true;
            check = 0;
    
            for (int m = 0; m < candidate_count; m++)
            {
                array[m] = 0;
                vertical[m] = 0;
            }
    
            for (int k = 0; k < candidate_count; k++)
            {
                for (int j = 0; j < MAX; j++)
                {
                    if (locked[k][j] == false)
                    {
                        array[k] += 1;
                    }
                    if (locked[j][k] == false) 
                    {
                        
                        vertical[k] += 1;
                    }       
                }
            }
    
            for (int o = 0; o < candidate_count; o++)
            {
                if (array[o] == MAX) 
                {
                    check += 1;
                }
                if (vertical[o] == MAX)
                {
                    vcheck += 1;
                }
            }
    
            if (check == 0 | vcheck == 0) 
            {
                locked[pairs[i].winner][pairs[i].loser] = false;
            }
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int winner;
    int rank;

    for (int i = 0; i < candidate_count; i++)
    {
        rank = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                rank++;
            }
        }

        // Prints all the names that are the source of the graph
        if (rank == candidate_count)
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}

