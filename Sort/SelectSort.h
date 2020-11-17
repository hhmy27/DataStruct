//
// Created by hmy on 2020/11/17.
//

#ifndef DATASTRUCT_SELECTSORT_H
#define DATASTRUCT_SELECTSORT_H

#include "tool.h"

void selectSort(int *A, int n) {
    for (int i = 0; i < n; i++) {
        int m = A[i];
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < m) {
                m = A[j];
                ind = j;
            }
        }
        swap(A[i], A[ind]);
    }
}

#endif //DATASTRUCT_SELECTSORT_H
