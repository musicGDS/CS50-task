// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

#define A_CODE 97

int dictSize = 0;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO

    int hash = hash(word);
    cursor = table[hash];

    while (true)
    {
        // reach end of the list
        if (cursor->next == NULL)
        {
            break;
        }
        // word found
        else if (strcasecmp(cursor->word, word))
        {
            return true;
        }
        else
        // continue itterating through list
        {
            curosr = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int hashCode = 0;
    // int first = (int) word[0];
    // int second = 0;

    // if (word[1] == '\0')
    // {
    //     second = A_CODE + 1;
    // }
    // else
    // {
    //     second = (int) word[1];
    // }

    // hashCode = (first - A_CODE) * (second - A_CODE);
    hashCode = (int) word[0];
    return hashCode;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    // create buffer
    char *tempWord = malloc((LENGTH + 1) * sizeof(char));
    // Open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        fclose(tempWord);
        return false;
    }
    // Read Strings from file one at the time
    while (true)
    {
        int result = fscanf(dict, "%s", tempWord);
        // check if it is not end of file
        if (result == EOF || resut < 1)
        {
            break;
        }


    // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            break;
        }
        // strcpy(n->word, tempWord)
        n->word = tempWord;
        n->next = NULL;


    // Hash word to obtain the hash value

        int hashnumber = hash(tempWord);

    // Insert node into hash table at that location
        // check if there is any nodes at the given hash
        if (table[hashnumber] == NULL)
        {
            table[hashnumber] = n;
        }
        else
        {
            n->next = table[hashnumber];
            table[hashnumber] = n;
        }

        dictSize++;
    }

    // close file and temp variable
    fclose(dict);
    fclose(tempWord);

    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictSize;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while(true)
        {
            if (cursor == NULL)
            {
                break;
            }
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    // TODO
    return true;
}
