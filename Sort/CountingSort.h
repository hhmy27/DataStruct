//
// Created by hmy on 2020/11/19.
//

#ifndef DATASTRUCT_COUNTINGSORT_H
#define DATASTRUCT_COUNTINGSORT_H

#include "tool.h"
#include <string.h>

void countingSort(int *A, int n) {
    if (n == 0)
        return;
    // use max - min create array can save space
    int max = A[0];
    int min = A[0];
    for (int i = 0; i < n; i++) {
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }
    int C[max - min + 1];
    memset(C, 0, sizeof(int) * (max - min + 1));

    for (int i = 0; i < n; i++) {
        C[A[i] - min]++;
    }

    int ind = 0;
    for (int i = 0; i < len(C); i++) {
        while (C[i]--) {
            A[ind++] = i + min;
        }
    }
}

#endif //DATASTRUCT_COUNTINGSORT_H
