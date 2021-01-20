#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

Node *empty = NULL;

Node *node(int value, Node *left, Node *right) {
    Node *r = malloc(sizeof(Node));
    r->marked = false;
    r->value = value;
    r->left = left;
    r->right = right;
    return r;
}


/* Basic Problems */

int size(Node *node) {
    if (node == NULL) {
        return 0;
    }
    if (node->marked == true) {
        return 0;
    }
    node->marked = true;
    return 1 + size(node->left) + size(node->right);
}


void unmark(Node *node) {
    if (node == NULL) {
        return;
    }
    if (node->marked == false) {
        return;
    }
    node->marked = false;
    unmark(node->right);
    unmark(node->left);

}

bool path_from(Node *node1, Node *node2) {
    if (node1 == NULL || node2 == NULL) {
        return false;
    }
    if (node1 == node2) {
        return true;
    }
    return (path_from(node1->left, node2) || path_from(node1->right, node2));
}

bool cyclic(Node *node) {
    /* TODO */
    bool p1 = path_from(node->right, node);
    bool p2 = path_from(node->left, node);
    return (p1 || p2);
}


/* Challenge problems */

void get_nodes(Node *node, Node **dest) {
    /* TODO */
}

void graph_free(Node *node) {
    /* TODO */
}


