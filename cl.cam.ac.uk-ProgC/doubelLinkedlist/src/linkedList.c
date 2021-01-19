//
// Created by Alexander Voloshenko on 18.01.2021.
//

#include "linkedList.h"
#include <stdlib.h>
#include "stdio.h"
#include "memcheck.h"

node *createNode(int data) {
    node *n = (node *) malloc(sizeof(node));
    n->next = NULL;
    n->data = data;
    return n;
}

void insertList(int data, node **head) {
    node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void freeList(node *head) {
    node *current = head;
    while (current != NULL) {
        node *prev = current;
        current = current->next;
        if (prev != NULL) {
            printf("free %p", prev);
            free(prev);
        }
    }
}

void printList(node *head) {
    if (head == NULL) {
        printf("Empty list ");
    }
    node *current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
}