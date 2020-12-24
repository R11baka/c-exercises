//
// Created by Alexander Voloshenko on 24.12.2020.
//
#include "stdio.h"

void swap(int *p, int *k) {
    int temp = *k;
    *k = *p;
    *p = temp;
}

void swapArr(int *arr, int i, int j) {
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void qs(int number[25], int first, int last) {
    int i, j, pivot, temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j) {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }

        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        qs(number, first, j - 1);
        qs(number, j + 1, last);

    }
}

void quicksort(int *list, int first, int last) {
    if (first < last) {
        int i = 0, j = last;
        int pivot = first;
        while (i < j) {
            while (list[pivot] >= list[i] && i < last) i++;
            while (list[pivot] < list[j] && j >= first) j--;
            if (i < j) {
                swapArr(list, j, i);
            }
        }
        swapArr(list, j, pivot);
        quicksort(list, first, j - 1);
        quicksort(list, j + 1, last);
    }
}

void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d->", arr[i]);
    }
    printf("\n");
}

int main() {
    int len = 6;
    int a[6] = {3, 2, 4, 1, 6, 9};

    printArr(a, len);
    quicksort(a, 0, len - 1);
    printArr(a, len);
    qs(a, 0, len - 1);
    printArr(a, len);
}