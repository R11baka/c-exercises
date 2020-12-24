#include "stdio.h"
#include "src/linked.h"
#include "src/linked.c"


int main(int argc, char *argv[]) {
    Node *head = initList();
    append(head, 3);
    append(head, 33);
    append(head, 333);
    append(head, 444);
    printList(head);
    deleteByIndex(head, 0);
    printList(head);
}
