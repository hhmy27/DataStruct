//
// Created by hmy on 2020/11/19.
//

#ifndef DATASTRUCT_SHELLSORT_H
#define DATASTRUCT_SHELLSORT_H

#include "tool.h"

// we choose initial m equal floor n/2
// in the inside sort, we use insert sort method
void shellSort(int *A, int n) {
    int m = n / 2;
    while (m) {
        // sort inside array
        for (int i = 0; i < n; i += m) {
            // use insert sort
            for (int j = i + m; j < n; j += m) {
                int v = A[j];
                int k = j - m;
                for (; k >= 0 && A[k] >= v; k -= m)
                    A[k + m] = A[k];
                A[k + m] = v;
            }
        }
        // keep sort inside array until m = 0
        m -= 1;
    }
}

#endif //DATASTRUCT_SHELLSORT_H
