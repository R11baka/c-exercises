//
// Created by Alexander Voloshenko on 16.12.2020.
//
#include "linked.h"
#include <stdlib.h>
#include "stdio.h"
#include <stdbool.h>

Node *initList() {
    Node *newNode = NULL;
    newNode = (Node *) malloc(sizeof(Node));
    return newNode;
}

void append(Node *n, nodeValue item) {
    Node *newNode = NULL, *currentNode;
    currentNode = n;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    newNode = (Node *) malloc(sizeof(Node));
    newNode->val = item;
    newNode->next = NULL;
    currentNode->next = newNode;
}

bool find(Node *head, nodeValue val) {
    bool result = false;
    Node *current;
    current = head;
    while (current != NULL) {
        if (current->val == val) {
            return true;
        }
        current = current->next;
    }
    return result;
}

bool deleteByIndex(Node *head, int index) {
    bool result = false;
    Node *current;
    current = head;
    int startIndex = 0;
    if (index == 0) {
        // delete head
        printf("delete head\n");
        Node *newHead = head->next;
        printItem(newHead);
        // pointer to pointer
        printf("delete ----");
        free(head);
        head = newHead;
        return true;
    }
    while (current != NULL) {
        if (index == startIndex) {
            // delete
        }
        current = current->next;
        startIndex++;
    }

    return result;
}

void printList(Node *head) {
    Node *current;
    current = head;
    while (current != NULL) {
        printItem(current);
        current = current->next;
    }
    printf("\n");
}

void printItem(Node *head) {
    printf("Address:[%p],val:%d ", head, head->val);
}
