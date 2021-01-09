//
// Created by Alexander Voloshenko on 09.01.2021.
//

#ifndef INC_6_087_LINKEDLIST_H
#define INC_6_087_LINKEDLIST_H

typedef struct node {
    int data;
    struct node *next;
} node;

void display(node *head);

node *addback(node *head, int data);

node *find(node *head, int data);

node *delnode(node *head, node *pelement);

void free_list(node *head);

#endif //INC_6_087_LINKEDLIST_H
