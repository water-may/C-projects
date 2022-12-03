#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

typedef struct
{
    string name;
    int votes;
}
candidates;
candidates person[9];

bool vote(string name);

int count = 0;
string winner;

int main(int argc, string argv[])
{
    for (int i = 0; i < (argc - 1); i++)
    {
        person[i].name = argv[i + 1];
        person[i].votes = 0;
        vote(person[i].name);
        count++;
    }
    
}


bool vote(string namo)
{   
    
}

