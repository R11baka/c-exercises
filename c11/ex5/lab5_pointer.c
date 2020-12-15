#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "memcheck.h"

void printLine(const int *arr, int size);

void update(int *current, int *next, int size);

int randInRange(int min, int max);

void initGeneration(int *current, int size);

int main(int argc, char *argv[]) {
    int *current, *next, *swap, j;
    int size, numberPfGenerations;
    if (argc < 3) {
        printf("User 2 arguments");
        exit(1);
    }
    size = atoi(argv[1]);
    numberPfGenerations = atoi(argv[2]);

    current = (int *) malloc(size * sizeof(int));
    next = (int *) malloc(size * sizeof(int));
    if (current == NULL || next == NULL) {
        fprintf(stderr, "Error! Memory allocation failed!\n");
        exit(1);
    }
    initGeneration(current, size);
    printLine(current, size);
    for (j = 0; j < numberPfGenerations; j++) {
        update(current, next, size);
        printLine(next, size);
        swap = current;
        current = next;
        next = swap;

    }
    printf("\n");
    free(current);
    free(next);
    print_memory_leaks();
    return 0;
}

int randInRange(int min, int max) {
    return min + (int) (rand() / (double) (RAND_MAX) * (max - min + 1));
}

void initGeneration(int *current, int size) {
    int i;
    for (i = 0; i < size; i++) {
        int r = randInRange(0, 1);
        if (r >= 1) {
            *(current + i) = 1;
        } else {
            *(current + i) = 0;
        }
    }
}

void update(int *current, int *next, int size) {
    int i;
    assert(size > 0);
    for (i = 0; i < size; i++) {
        int h, k;
        if (i == 0) {
            h = 0;
        } else {
            h = *(current + i - 1);
        }
        if (i == size) {
            k = 0;
        } else {
            k = *(current + i + 1);
        }
        if (current[i] == 0 && (k == 1 || h == 1)) {
            *(next + i) = 1;
        } else {
            *(next + i) = 0;
        }
    }
}

void printLine(const int *arr, int size) {
    int i;
    assert(size > 0);
    for (i = 0; i < size; i++) {
        if (*(arr + i) == 0) {
            printf(".");
        } else {
            printf("*");
        }
        printf(" ");
    }
    printf("\n");
}
