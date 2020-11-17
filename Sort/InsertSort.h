//
// Created by hmy on 2020/11/17.
//

#ifndef DATASTRUCT_INSERTSORT_H
#define DATASTRUCT_INSERTSORT_H

#include "tool.h"

void insertSort(int *A, int n) {
    for (int i = 1; i < n; i++) {
        int v = A[i];
        int j = i - 1;
        for (; j >= 0 && A[j] >= v; j--)
            A[j + 1] = A[j];
        A[j + 1] = v;
    }
}

#endif //DATASTRUCT_INSERTSORT_H
