//
// Created by Alexander Voloshenko on 09.01.2021.
//

#ifndef INC_6_087_TREENODE_H
#define INC_6_087_TREENODE_H
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} tnode;

tnode *talloc(int data);

void preorder(tnode *root);

void inorder(tnode *root);

void postorder(tnode *root);

int delTree(tnode *root);
tnode *addnode(tnode *root, int data);

#endif //INC_6_087_TREENODE_H
