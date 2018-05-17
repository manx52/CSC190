/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"
#define SIZE 26

typedef struct node {
    char word[LENGTH + 1];
    struct node* next;
}node;

node* hashTable[SIZE];
unsigned int count = 0;

int hash(const char* key) {
    int hashIndex = toupper(key[0]) - 'A';
    return hashIndex % SIZE;
}
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word) {
    if (word == NULL) 
        return false;
        
    int index = hash(word);
    node* newptr = hashTable[index];
    
    if(newptr == NULL) 
        return false;
    
    char temp[LENGTH + 1];
    
    for (int i = 0,n = strlen(word); i <= n; i++) 
        temp[i] = tolower(word[i]);    
        
    temp[strlen(word) + 1] = '\0';
    
    while (newptr != NULL) {
        
        if (strcmp(newptr->word,temp) == 0) {
            return true;
        }
        
        newptr = newptr->next;
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary) {
    FILE* fp = fopen(dictionary,"r");
    
        if(fp == NULL) {
            return false;
        }
        
        char temp[LENGTH + 1];
        
       for (int i = 0; i < SIZE; i++) 
        hashTable[i] = NULL;
        
       
    while(fscanf(fp,"%s",temp) != EOF) {
        node* newptr = malloc(sizeof(node));

        strcpy(newptr->word, temp); 
        
        int index = hash(temp);
        
        if (hashTable[index] == NULL) {
            hashTable[index] = newptr;
            newptr->next = NULL;
            count++;
        }
        else {
            newptr->next = hashTable[index];
            hashTable[index] = newptr;
            count++;
        }
        
    }
    
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void) {
    
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void) {
    for (int i = 0; i < SIZE + 1; i++) {
        node* ptr = hashTable[i];
        
        while (ptr != NULL) {
          node* temp = ptr;
          ptr = ptr->next;
          free(temp); 
        }
        hashTable[i] = NULL;
    }
    return true;
}
