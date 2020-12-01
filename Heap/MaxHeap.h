//
// Created by hmy on 2020/11/21.
//

#ifndef DATASTRUCT_MAXHEAP_H
#define DATASTRUCT_MAXHEAP_H

#include <stdlib.h>
#include "../tool.h"


typedef struct max_heap {
    int size;
    int *array;
} max_heap, *MaxHeap;

// construct max heap
void maxHeapify(MaxHeap heap, int ind) {
    int min_ind = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    int *arr = heap->array;
    int size = heap->size;

    // select minimal number in root, left, right
    if (left < size && arr[left] > arr[min_ind])
        min_ind = left;
    if (right < size && arr[right] > arr[min_ind])
        min_ind = right;

    if (min_ind != ind) {
        swap(arr[ind], arr[min_ind]);
        maxHeapify(heap, min_ind);
    }
}

MaxHeap createMaxHeap(int *A, int n) {
    MaxHeap heap = (MaxHeap) malloc(sizeof(max_heap));
    heap->array = A;
    heap->size = n;

    for (int i = (n - 2) / 2; i >= 0; i--) {
        maxHeapify(heap, i);
    }

    return heap;
}

MaxHeap createMaxHeap_deep(int *A, int n) {
    MaxHeap heap = (MaxHeap) malloc(sizeof(max_heap));
    heap->array = (int *) malloc(sizeof(int) * n);
    heap->size = n;

    for (int i = 0; i < n; i++) {
        heap->array[i] = A[i];
    }

    for (int i = (n - 1) / 2; i >= 0; i--) {
        maxHeapify(heap, i);
    }

    return heap;
}

int popMaxHeapRoot(MaxHeap heap) {
    int *arr = heap->array;
    // get root number
    int n = arr[0];
    swap(arr[0], arr[heap->size - 1]);
    heap->size -= 1;
    maxHeapify(heap, 0);
    return n;
}


#endif //DATASTRUCT_MAXHEAP_H
