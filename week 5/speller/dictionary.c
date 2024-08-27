// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
// Number of buckets in hash table
const unsigned int N = 100000;
// Hash table
node *table[N];
int dict_size = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *dict_pointer = fopen(dictionary, "r");
    // Check if null
    if (dictionary == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }
    // Initialise word array
    char next_word[LENGTH + 1];
    // Read strings from file one at a time
    while (fscanf(dict_pointer, "%s", next_word) != EOF)
    {
        // Create new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        // copy word into node using strcopy
        strcpy(n->word, next_word);
        // Hash word to obtain hash value
        int hash_value = hash(next_word);
        // Insert node into hash table at that location
        n->next = table[hash_value];
        table[hash_value] = n;
        dict_size++;
    }
    // Close file
    fclose(dict_pointer);
return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Function should take a string and return an index
    // This hash function adds the ASCII values of all characters in     the word together
    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Hash word to obtain hash value
    int hash_value = hash(word);
    // Access linked list at that index in hash table
    node *n = table[hash_value];
    // Traverse linked list, looking for word (strcasecomp)
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Iterate over hash table and free nodes in each linked list
    for (int i = 0; i < N; i++)
    {
        // Assign cursor
        node *n = table[i];
        // Loop through linked list
        while (n != NULL)
        {
            // Make temp equal cursor;
            node *tmp = n;
            // Point cursor to next element
            n = n->next;
            // free temp
            free(tmp);
        }
        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
return false;
}








// // Implements a dictionary's functionality

// #include <ctype.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <strings.h>

// #include "dictionary.h"

// #define HASHTABLE_SIZE 10000

// // Defines struct for a node
// typedef struct node
// {
//     char word[LENGTH + 1];
//     struct node *next;
// }
// node;

// node *hashtable[HASHTABLE_SIZE];

// // Hashes the word (hash function posted on reddit by delipity)
// // The word you want to hash is contained within new node, arrow, word.
// // Hashing that will give you the index. Then you insert word into linked list.
// unsigned int hash(const char *word)
// {
//     unsigned int hash = 0;
//     for (int i = 0, n = strlen(word); i < n; i++)
//     {
//         hash = (hash << 2) ^ word[i];
//     }
//     return hash % HASHTABLE_SIZE;
// }

// // Initializes counter for words in dictionary
// int word_count = 0;

// // Loads dictionary into memory, returning true if successful else false
// bool load(const char *dictionary)
// {
//     // Opens dictionary
//     FILE *file = fopen(dictionary, "r");
//     if (file == NULL)
//     {
//         return false;
//     }
//     // Scans dictionary word by word (populating hash table with nodes containing words found in dictionary)
//     char word[LENGTH + 1];
//     while (fscanf(file, "%s", word) != EOF)
//     {
//         // Mallocs a node for each new word (i.e., creates node pointers)
//         node *new_node = malloc(sizeof(node));
//         // Checks if malloc succeeded, returns false if not
//         if (new_node == NULL)
//         {
//             unload();
//             return false;
//         }
//         // Copies word into node if malloc succeeds
//         strcpy(new_node->word, word);

//         // Initializes & calculates index of word for insertion into hashtable
//         int h = hash(new_node->word);

//         // Initializes head to point to hashtable index/bucket
//         node *head = hashtable[h];

//         // Inserts new nodes at beginning of lists
//         if (head == NULL)
//         {
//             hashtable[h] = new_node;
//             word_count++;
//         }
//         else
//         {
//             new_node->next = hashtable[h];
//             hashtable[h] = new_node;
//             word_count++;
//         }
//     }
//     fclose(file);
//     return true;
// }

// // Returns true if word is in dictionary else false
// bool check(const char *word)
// {
//     // Creates copy of word on which hash function can be performed
//     int n = strlen(word);
//     char word_copy[LENGTH + 1];
//     for (int i = 0; i < n; i++)
//     {
//         word_copy[i] = tolower(word[i]);
//     }
//     // Adds null terminator to end string
//     word_copy[n] = '\0';
//     // Initializes index for hashed word
//     int h = hash(word_copy);
//     // Sets cursor to point to same address as hashtable index/bucket
//     node *cursor = hashtable[h];
//     // Sets cursor to point to same location as head

//     // If the word exists, you should be able to find in dictionary data structure.
//     // Check for word by asking, which bucket would word be in? hashtable[hash(word)]
//     // While cursor does not point to NULL, search dictionary for word.
//     while (cursor != NULL)
//     {
//         // If strcasecmp returns true, then word has been found
//         if (strcasecmp(cursor->word, word_copy) == 0)
//         {
//             return true;
//         }
//         // Else word has not yet been found, advance cursor
//         else
//         {
//             cursor = cursor->next;
//         }
//     }
//     // Cursor has reached end of list and word has not been found in dictionary so it must be misspelled
//     return false;
// }

// // Returns number of words in dictionary if loaded else 0 if not yet loaded
// unsigned int size(void)
// {
//     return word_count;
// }

// // Unloads dictionary from memory, returning true if successful else false
// bool unload(void)
// {
//     node *head = NULL;
//     node *cursor = head;
//     // freeing linked lists
//     while (cursor != NULL)
//     {
//         node *temp = cursor;
//         cursor = cursor->next;
//         free(temp);
//     }
//     return true;
// }
