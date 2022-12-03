// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"


#define HASHTABLE_SIZE 10000




// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[HASHTABLE_SIZE];

// Number of buckets in hash table
const unsigned int N = 1;

int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Creates copy of word on which hash function can be performed
    int n = strlen(word);
    char word_copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    // Adds null terminator to end string
    word_copy[n] = '\0';
    // Initializes index for hashed word
    int h = hash(word_copy);
    // Sets cursor to point to same address as hashtable index/bucket
    node *cursor = hashtable[h];
    // Sets cursor to point to same location as head

    // If the word exists, you should be able to find in dictionary data structure.
    // Check for word by asking, which bucket would word be in? hashtable[hash(word)]
    // While cursor does not point to NULL, search dictionary for word.
    while (cursor != NULL)
    {
        // If strcasecmp returns true, then word has been found
        if (strcasecmp(cursor->word, word_copy) == 0)
        {
            return true;
        }
        // Else word has not yet been found, advance cursor
        else
        {
            cursor = cursor->next;
        }
    }
    // Cursor has reached end of list and word has not been found in dictionary so it must be misspelled
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    signed int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % HASHTABLE_SIZE;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // Scans dictionary word by word (populating hash table with nodes containing words found in dictionary)
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Mallocs a node for each new word (i.e., creates node pointers)
        node *new_node = malloc(sizeof(node));
        // Checks if malloc succeeded, returns false if not
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        // Copies word into node if malloc succeeds
        strcpy(new_node->word, word);

        // Initializes & calculates index of word for insertion into hashtable
        int h = hash(new_node->word);

        // Initializes head to point to hashtable index/bucket
        node *head = hashtable[h];

        // Inserts new nodes at beginning of lists
        if (head == NULL)
        {
            hashtable[h] = new_node;
            word_count++;
        }
        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
            word_count++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *head = NULL;
    node *cursor = head;
    // freeing linked lists
    while (cursor != NULL)
    {
        node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return true;
}
