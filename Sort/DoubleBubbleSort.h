//
// Created by hmy on 2020/11/17.
//

#ifndef DATASTRUCT_DOUBLEBUBBLESORT_H
#define DATASTRUCT_DOUBLEBUBBLESORT_H

#include "tool.h"

void doubleBubbleSort(int *A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) swap(A[j], A[j + 1]);
        }
        for (int k = n - i - 1; k > i; k--) {
            if (A[k] < A[k - 1]) swap(A[k], A[k - 1]);
        }
    }
}

#endif //DATASTRUCT_DOUBLEBUBBLESORT_H
