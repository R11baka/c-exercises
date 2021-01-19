//
// Created by Alexander Voloshenko on 18.01.2021.
//
#include "src/linkedList.h"
#include "stdio.h"
#include "src/memcheck.h"

int main() {
    node *head = NULL;
    insertList(3, &head);
    insertList(4, &head);
    insertList(6, &head);
    printList(head);
    freeList(head);
    print_memory_leaks();
}
