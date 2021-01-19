#include <stdlib.h>
#include "stdio.h"
#include "tree.h"
#include "memcheck.h"

Tree *empty = NULL;

/* BASE EXERCISE */

int tree_member(int x, Tree *tree) {
    int result = 0;
    if (tree == NULL) {
        return 0;
    }
    if (tree->value == x) {
        return 1;
    }
    int r1 = tree_member(x, tree->right);
    int r2 = tree_member(x, tree->left);
    if (r1 == 1 || r2 == 1) {
        return 1;
    }
    return 0;
}

Tree *tree_insert(int x, Tree *tree) {

    if (tree == NULL) {
        Tree *node = (Tree *) malloc(sizeof(Tree));
        node->left = NULL;
        node->right = NULL;
        node->value = x;
        return node;
    }
    if (tree->value > x) {
        tree->right = tree_insert(x, tree->right);
    } else {
        tree->left = tree_insert(x, tree->left);
    }
    return tree;
}

void tree_free(Tree *tree) {
    if (tree != NULL) {
        tree_free(tree->left);
        tree_free(tree->right);
        free(tree);
    }
}


void tree_print(Tree *tree) {
    if (tree == NULL) {
        printf("empty tree");
        return;
    }
    printf("tree val:%d\n", tree->value);
    tree_print(tree->left);
    tree_print(tree->right);

}

/* CHALLENGE EXERCISE */

void pop_minimum(Tree *tree, int *min, Tree **new_tree) {
    Tree *current = tree;
    while (current->right != NULL) {
        current = current->right;
    }
    *min = current->value;
}

Tree *tree_remove(int x, Tree *tree) {
    /* TODO */
    return empty;
}
