#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "phonebook_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead[])
{
    unsigned int n = BKDRHash(lastName);

    entry *tmp;
    tmp = pHead[n]->pNext;
    while (tmp != NULL) {
        if (strcasecmp(lastName, tmp->lastName) == 0)
            return tmp;
        tmp = tmp->pNext;
    }
    return NULL;
}

void append(char lastName[], entry *e[])
{
    /* allocate memory for the new entry and put lastName */
    unsigned int n = BKDRHash(lastName);

    e[n]->pNext = (entry *) malloc(sizeof(entry));
    e[n] = e[n]->pNext;
    strcpy(e[n]->lastName, lastName);
    e[n]->pNext = NULL;
}

// BKDR Hash Function
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str) {
        hash = hash * seed + (*str++);
    }

    //HASH_TABLE_SIZE define in phonebook_hash.h
    return (hash % HASH_TABLE_SIZE);
}
