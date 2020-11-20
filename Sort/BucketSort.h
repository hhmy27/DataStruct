//
// Created by hmy on 2020/11/20.
//

#ifndef DATASTRUCT_BUCKETSORT_H
#define DATASTRUCT_BUCKETSORT_H

#include "tool.h"
#include "../List/LinkList/SingleLinkList/SingleLinkList.h"

void bucketSort(int *A, int n) {
    if (n == 0)
        return;
    const int BUCKET_SIZE = 5;

    // use max - min create array can save space
    int max = A[0];
    int min = A[0];
    for (int i = 0; i < n; i++) {
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }

    int d = max - min + 1;
    LinkList buckets[d];
    for (int i = 0; i < d; i++) {
        buckets[i] = createEmptyLinkList();
    }

    for (int i = 0; i < n; i++) {
        // map function: f(A[i]) = ((A[i] - min) / BUCKET_SIZE)
        insertNodeHead(buckets[(A[i] - min) / BUCKET_SIZE], A[i]);
    }

    // sort bucket
    for (int i = 0; i < d; i++) {
        sortLinkList(buckets[i]);
    }

    int ind = 0;
    for (int i = 0; i < d; i++) {
        Array a = transformToArray(buckets[i]);
        int *arr = a->arr;
        for (int j = 0; j < a->size; j++) {
            A[ind++] = arr[j];
        }
    }
}


#endif //DATASTRUCT_BUCKETSORT_H
