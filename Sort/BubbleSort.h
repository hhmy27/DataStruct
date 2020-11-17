//
// Created by hmy on 2020/11/17.
//

#ifndef DATASTRUCT_BUBBLESORT_H
#define DATASTRUCT_BUBBLESORT_H

#include "tool.h"

void bubbleSort(int *A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) swap(A[j], A[j + 1]);
        }
    }
}

#endif //DATASTRUCT_BUBBLESORT_H
