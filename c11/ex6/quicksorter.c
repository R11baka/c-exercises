#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "src/linked_list.h"
#include "src/memcheck.h"


int main(int argc, char *argv[]) {
    node *sortedList = NULL;
    if (argc == 1) {
        printf("usage: quicksorter [-q] number1 [number2 ... ]\n");
    }
    node *intiList = NULL;
    for (int i = 1; i < argc; i++) {
        intiList = create_node(atoi(argv[i]), intiList);
    }
    sortedList = quickSort(intiList);
    assert(is_sorted(sortedList));
    print_list(sortedList);
    free_list(intiList);
    free_list(sortedList);
    print_memory_leaks();
    return 0;
}
