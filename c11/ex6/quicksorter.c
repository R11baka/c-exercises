#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "src/linked_list.h"
#include "src/memcheck.h"



int main(int argc, char *argv[]) {
    node *tail = NULL;
    if (argc == 1) {
        printf("usage: quicksorter [-q] number1 [number2 ... ]\n");
    }
    node *t = NULL;
    t = create_node(2, t);
    t = create_node(3, t);
    tail = quickSort(t);
    printf("LIST \n");
    print_list(tail);
    printf("   end list");
    return 0;
}
