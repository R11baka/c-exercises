#ifndef GRAPH_H
#define GRAPH_H 1

#include <stdbool.h>

struct node {
  bool marked;
  int value;
  struct node *left;
  struct node *right;
};
typedef struct node Node;

/* Predefined constructors */

Node *empty;
Node *node(int value, Node *left, Node *right);

/* Basic problems */

int size(Node *node);

void unmark(Node *node);

bool path_from(Node *node1, Node *node2);

bool cyclic(Node *node);

/* Challenge problems */

void get_nodes(Node *node, Node *dest[]);
void graph_free(Node *node);

#endif 
