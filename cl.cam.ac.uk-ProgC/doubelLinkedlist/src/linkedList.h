//
// Created by Alexander Voloshenko on 18.01.2021.
//

#ifndef CL_CAM_AC_UK_PROGC_LINKEDLIST_H
#define CL_CAM_AC_UK_PROGC_LINKEDLIST_H

typedef struct tnode {
    int data;
    struct tnode *next;
} node;

void insertList(int data, node **head);

void removeList(int data, node **head);

void freeList(node *head);

void printList(node *head);

#endif //CL_CAM_AC_UK_PROGC_LINKEDLIST_H
