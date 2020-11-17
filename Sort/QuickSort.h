//
// Created by hmy on 2020/11/17.
//

#ifndef DATASTRUCT_QUICKSORT_H
#define DATASTRUCT_QUICKSORT_H

#include "tool.h"

void quickSort__(int *A, int left, int right) {
    if (left >= right)
        return;
    int val = A[left];
    int i = left, j = right;
    while (i < j) {
        for (; i < j && A[j] >= val; j--);
        A[i] = A[j];
        for (; i < j && A[i] <= val; i++);
        A[j] = A[i];
    }
    A[i] = val;
    quickSort__(A, left, i - 1);
    quickSort__(A, i + 1, right);
}

void quicksort(int *A, int n) {
    quickSort__(A, 0, n - 1);
}


#endif //DATASTRUCT_QUICKSORT_H
