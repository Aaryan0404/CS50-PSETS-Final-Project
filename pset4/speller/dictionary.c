// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>


#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N] = {NULL};

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
int y = 0;
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        node *dict_word = malloc(sizeof(node));
        if (dict_word == NULL)
        {
            unload();
            return false;
        }
        else
        {
            strcpy(dict_word->word, word);
            int x = hash(dict_word->word);
            if (y != 0)
            {
                dict_word->next = hashtable[x];
            }
            hashtable[x] = dict_word;
            if (y == 0)
            {
                hashtable[x]->next = NULL;
            }
            y++;
        }
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return y;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node* traverser = NULL;
    traverser = hashtable[hash(word)];
    
    while(traverser != NULL)
    {
        char *m = traverser->word;
        int f = strcasecmp(word, m);
        if (f != 0)
        {
            traverser = traverser->next;   
        }
        else
        {
            return true;
            free(traverser);
        }
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int l = 0; l < N; l++)
    {
        node* alpha = hashtable[l];
        while (alpha != NULL)
        {
            node *temp = alpha;
            alpha = alpha->next;
            free(temp);
        }
    }
    return true;
}
