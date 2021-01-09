//
// Created by Alexander Voloshenko on 09.01.2021.
//
#include <stdio.h>
#include "linkedList.h"
#include "stdlib.h"
#include "memcheck.h"

void display(node *list) {
    node *p = list;
    while (p != NULL) {
        printf("Data:%d address:%p ", p->data, (void *) p);
        p = p->next;
    }
    printf("\n");
}

node *addback(node *head, int data) {
    node *newNode = (node *) malloc(sizeof(head));
    if (newNode == NULL) {
        free(newNode);
        perror("Cant init new node\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void free_list(node *list) {
    node *prevNode = NULL;
    while (list != NULL) {
        prevNode = list;
        list = list->next;
        free(prevNode);
        prevNode = NULL;
    }
}

node *find(node *head, int data) {
    node *t = head;
    while (t != NULL) {
        if (t->data == data) {
            return t;
        }
        t = t->next;
    }
    return NULL;
}

// del from head
// del from end
// del from middle
node *delnode(node *head, node *pelement) {
    node *t = head;
    if (t == pelement) {
        t = t->next;
        free(pelement);
        return t;
    }
    node *prevNode = t, *currentNode = t, *nextNode = t;
    while (currentNode != NULL && nextNode != NULL) {
        prevNode = currentNode;
        currentNode = nextNode;
        nextNode = currentNode->next;
        if (currentNode == pelement) {
            free(pelement);
            prevNode->next = nextNode;

        }
    }
    return head;
}