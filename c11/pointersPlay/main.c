#include "stdio.h"

#define N 10

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int findMinIndex(int a[], int startIndex, int len) {
    int minIndex = startIndex,
            minElem = a[minIndex];
    for (int i = startIndex; i < len; i++) {
        if (a[i] < minElem) {
            minElem = a[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printArr(int a[], int l) {
    for (int i = 0; i < l; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int a[N] = {9, 8, 6, 7, 4, 3, 3, 2, 1, 0};
    int t;
    printArr(a, N);
    swap(&a[0], &a[9]);
    // buble sort
    t = findMinIndex(a, 0, 10);
    for (int i = 0; i < N; i++) {
        int m = findMinIndex(a, i, N);
        swap(&a[i], &a[m]);
    }
    printArr(a, N);
    printf("Min index:%d", t);
}
