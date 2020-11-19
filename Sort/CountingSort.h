//
// Created by hmy on 2020/11/19.
//

#ifndef DATASTRUCT_COUNTINGSORT_H
#define DATASTRUCT_COUNTINGSORT_H

#include "tool.h"

void countingSort(int *A, int n) {
    if (n == 0)
        return;
    int max = A[0];
    int min = A[0];
    for (int i = 0; i < n; i++) {
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }
    int

}

#endif //DATASTRUCT_COUNTINGSORT_H
