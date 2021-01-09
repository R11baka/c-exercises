//
// Created by Alexander Voloshenko on 09.01.2021.
//
#include "treeNode.h"
#include "memcheck.h"
#include <stdio.h>

tnode *tcalloc(int data) {
    tnode *p = malloc(sizeof(tnode));
    if (p == NULL) {
        free(p);
        exit(1);
    }
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;

}

tnode *addnode(tnode *root, int data) {
    if (root == NULL) {
        return tcalloc(data);
    }
    if (data < root->data) {
        root->left = addnode(root->left, data);
    } else {
        root->right = addnode(root->right, data);
    }
    return root;
}

void preorder(tnode *root) {
    if (root == NULL) {
        return;
    }
    printf("Node elem %d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(tnode *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->right);
    postorder(root->left);
    printf("Node elem %d ", root->data);
}

void inorder(tnode *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("Node elem %d ", root->data);
    inorder(root->right);
}

int delTree(tnode *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return 1;
    }
    int n1 = delTree(root->right);
    int n2 = delTree(root->left);
    free(root);
    return n1 + n2;
}
