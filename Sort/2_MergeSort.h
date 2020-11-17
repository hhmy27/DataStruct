//
// Created by hmy on 2020/11/17.
//

#ifndef DATASTRUCT_2_MERGESORT_H
#define DATASTRUCT_2_MERGESORT_H

#include "tool.h"

void merge(int *A, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (j = 0; j < n2; j++) {
        R[j] = A[mid + j + 1];
    }

    i = j = 0;
    k = left;
    // compare L[i] and R[j] than assign smaller number to A[k], and add 1 to relevant index to iterate rest of number
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }
    while (i < n1)A[k++] = L[i++];
    while (j < n2)A[k++] = R[j++];

}

void mergeSort__(int *A, int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort__(A, left, mid);
    mergeSort__(A, mid + 1, right);
    merge(A, left, mid, right);
}


void mergeSort(int *A, int n) {
    quickSort__(A, 0, n - 1);
}

#endif //DATASTRUCT_2_MERGESORT_H
