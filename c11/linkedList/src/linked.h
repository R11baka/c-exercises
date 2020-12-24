//
// Created by Alexander Voloshenko on 16.12.2020.
//
#include <stdbool.h>

#ifndef C11_LINKED_H
#define C11_LINKED_H

typedef int nodeValue;
typedef struct _node {
    nodeValue val;
    struct _node *next;
} Node;

bool find(Node *head, nodeValue val);

void append(Node *n, nodeValue item);

bool deleteByIndex(Node *head, int index);
void printItem(Node *head);

#endif //C11_LINKED_H
