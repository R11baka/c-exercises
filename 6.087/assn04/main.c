
#include <stdio.h>
#include "src/treeNode.h"
#include "src/memcheck.h"

int main(void) {
    tnode *root1 = NULL;
    root1 = addnode(NULL, 3);
    root1 = addnode(root1, 1);
    printf("\n");
    int t = delTree(root1);
    printf("count deleted %d", t);

    print_memory_leaks();
}
