/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include "dictionary.h"
#include<ctype.h>
#include<string.h>

int count = 0;     

struct node 
{         
    bool is_word;
    struct node *children[27];
};

struct node root=(struct node){false,{NULL}};

int hashValue(char key);   

void freeData(struct node *currentData);

/*

 * Returns true if word is in dictionary else false.

 */
bool check(const char *word)
{
    struct node *trav = &root;
    for (int i=0;i<strlen(word);i++)
    {
        int value=hashValue(word[i]);
        if (trav->children[value] == NULL)
            return false;                               
        trav = trav->children[value];      
    }
    if (trav->is_word)  
        return true;
    else
        return false;
}

/*

 * Loads dictionary into memory.  Returns true if successful else false.

 */

bool load(const char *dictionary)
{
    FILE *fp = fopen(dictionary,"r");
    if (fp == NULL)
        return false;
    while (!feof(fp))
    {
        char word[LENGTH+1] = {};
        fscanf(fp,"%s\n",word); 
        count++;    
        struct node *trav = &root;
        for (int i=0;i<strlen(word);i++)
        {
            if (trav->children[hashValue(word[i])] == NULL)  
            {
                struct node *new = malloc(sizeof(struct node));   
                *new = (struct node) {false,{NULL}};      
                trav->children[hashValue(word[i])] = new;
                trav = new;
            }
            else
            {
                trav = trav->children[hashValue(word[i])];  
            }
         }
         trav->is_word = true;  
    }
    fclose(fp);         
    return true;
}

/*

 * caculate a number for the character

 */
int hashValue(char key)
{
    int num;
    if (key == '\'')
        return 26;
    else if(key >= 'A' && key <= 'Z')
        key += 32;
    num = key - 'a';
    return num;
}
/*

 * Returns number of words in dictionary if loaded else 0 if not yet loaded.

 */
unsigned int size(void)
{
    if (count)
        return count;
    return 0;
}
/*

 * Unloads dictionary from memory.  Returns true if successful else false.

 */
bool unload(void)
{
    for (int i=0;i<27;i++)            
    {
        if (root.children[i] != NULL)  
            freeData(root.children[i]);
    }
    return true;         // can't figure out when to return false...
}
void freeData(struct node *currentData)
{
    for (int i=0;i<27;i++)
    {
        if (currentData->children[i] != NULL)   
            freeData(currentData->children[i]); 
    }
    free(currentData);
 }