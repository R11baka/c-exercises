/*
 * CS 11, C Track, lab 7
 *
 * FILE: hash_table.c
 *     Implementation of the hash table functionality.
 *
 */

/*
 * Include the declaration of the hash table data structures
 * and the function prototypes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "memcheck.h"


/*** Hash function. ***/

int hash(char *s) { // for loop on this
    int res = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        res = res + (int) s[i];
    }
    return res % NSLOTS;
}


/*** Linked list utilities. ***/

/* Create a single node. */
node *create_node(char *key, int value) {
    node *n = (node *) malloc(sizeof(node));
    if (n == NULL) {
        fprintf(stderr, "Fatal error: out of memory. "
                        "Terminating program.\n");
        exit(1);
    }
    n->key = key;
    n->value = value;
    n->next = NULL;
    return n;
}

/* Free all the nodes of a linked list. */
void free_list(node *list) {
    if (list == NULL) {
        return;
    }
    node *n = list;
    while (n != NULL) {
        node *currentNode = n;
        node *nextNode = n->next;
        free(currentNode);
        n = nextNode;
    }
}


/*** Hash table utilities. ***/

/* Create a new hash table. */
hash_table *create_hash_table() {
    hash_table *ht = malloc(sizeof(hash_table));
    node **slots = malloc(NSLOTS * sizeof(node *));
    for (int i = 0; i < NSLOTS; i++) {
        slots[i] = NULL;
    }
    ht->slot = slots;
    free(slots);
    return ht;
}


/* Free a hash table. */
void free_hash_table(hash_table *ht) {
    for (int i = 0; i < NSLOTS; i++) {
        if (ht->slot[i] != NULL) {
            free_list(ht->slot[i]);
        }
    }
    free(ht);
}


/*
 * Look for a key in the hash table.  Return 0 if not found.
 * If it is found return the associated value.
 */
int get_value(hash_table *ht, char *key) {
    node **slots = ht->slot;
    int h = hash(key);
    node *list = slots[h];
    while (list != NULL) {
        //   if (list->key == key) {
        if (strcmp(list->key, key) == 0) {
            return list->value;
        }
        list = list->next;
    }
    return 0;
}


/*
 * Set the value stored at a key.  If the key is not in the table,
 * create a new node and set the value to 'value'.  Note that this
 * function alters the hash table that was passed to it.
 */
void set_value(hash_table *ht, char *key, int value) {
    node *n = create_node(key, value);
    int h = hash(key);
    node *currentNode = ht->slot[h];
    if (currentNode == NULL) {
        ht->slot[h] = n;
    } else {
        node *prevNode = NULL;
        while (currentNode != NULL) {
            if (strcmp(currentNode->key, key) == 0) {
                currentNode->value = value;
                free(n);
                return;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        prevNode->next = n;
    }
}

void print_list(node *list) {
    node *n = list;
    while (n != NULL) {
        printf("%s %d \n", n->key, n->value);
        n = n->next;
    }
}

/* Print out the contents of the hash table as key/value pairs. */
void print_hash_table(hash_table *ht) {
    node **slots = ht->slot;
    for (int i = 0; i < NSLOTS; i++) {
        node *n = slots[i];
        if (n != NULL) {
            print_list(n);
        }
    }
    printf("\n");
}


