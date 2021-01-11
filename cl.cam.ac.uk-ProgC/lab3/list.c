#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *cons(int head, List *tail) {
    /* malloc() will be explained in the next lecture! */
    List *cell = malloc(sizeof(List));
    cell->head = head;
    cell->tail = tail;
    return cell;
}

/* Functions for you to implement */

int sum(List *list) {
    int result = 0;
    List *head = list;
    while (head != NULL) {
        result = result + head->head;
        head = head->tail;
    }
    return result;
}

void iterate(int (*f)(int), List *list) {
    List *head = list;
    while (head != NULL) {
        head->head = f(head->head);
        head = head->tail;
    }
}

void iterateL(void (*f)(List *l), List *list) {
    List *head = list;
    while (head != NULL) {
        f(head);
        head = head->tail;
    }
}

void changeHead(List *l) {
    l->head = l->head + 1;
}

void print_list(List *list) {
    if (list == NULL) {
        printf("[]");
        return;
    }
    List *head = list;
    printf("[");
    while (head != NULL) {
        printf("%d", head->head);
        if (head->tail != NULL) {
            printf(",");
        }
        head = head->tail;
    }
    printf("]");
    printf("\n");
}

/**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2) {
    List *tail1 = list1;
    List *tail2 = list2;
    List *mergedTail = NULL;
    while (tail1 != NULL && tail2 != NULL) {
        if (tail1->head >= tail2->head) {
            if (mergedTail == NULL) {
                mergedTail = tail2;
            } else {
                mergedTail->tail = tail1;
            }
            tail2 = tail2->tail;
        } else {
            if (mergedTail == NULL) {
                mergedTail = tail1;
            } else {
                mergedTail->tail = tail2;
            }
            tail1 = tail1->tail;
        }
    }
    if (tail1 != NULL) {
        mergedTail->tail = tail1;
    } else {
        mergedTail->tail = tail2;
    }
    return mergedTail;
}

void split(List *list, List **list1, List **list2) {
    /* TODO */
}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */
/*
List *mergesort(List *list) { 
  if (list == NULL || list->tail == NULL) { 
    return list;
  } else { 
    List *list1;
    List *list2;
    split(list, &list1, &list2);
    list1 = mergesort(list1);
    list2 = mergesort(list2);
    return merge(list1, list2);
  }
}
 */
