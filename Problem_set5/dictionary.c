// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];
unsigned int counter = 0 ;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char lower[strlen(word) + 1];
    // convert to lowercase 
    for (int i = 0 , n = strlen(word); i <= n ; i++)
    {
        lower[i] = tolower(word[i]);
    }
    
    node *cursor = table[hash(lower)];
    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0 , n = strlen(word) ; i < n ; i++)
        hash = (hash << 2) ^ word[i];
    return hash % N;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char ww[LENGTH+1];
    FILE *file = fopen(dictionary , "r");
    if (file == NULL) 
    {
        return false;
    }
    while(fscanf(file, "%s", ww) != EOF)
    {
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            unload();
            return false;
        }
        else
        {
            counter++;
            strcpy(n->word , ww);
            //n->next = NULL ;
            int hash_num = hash(n->word);
            n->next = table[hash_num];
            table[hash_num] = n ;
            
        }
        
    }
    fclose(file);
    
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0 ; i < N ; i++){
        node *cursor = table[i];
        while(cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        free(cursor);
    }
    
    return true;
}
