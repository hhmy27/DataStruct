//
// Created by hmy on 2020/11/21.
//

#ifndef DATASTRUCT_MINHEAP_H
#define DATASTRUCT_MINHEAP_H

#include "stdlib.h"


typedef struct min_heap {
    int size;
    int *array;
} min_heap, *MinHeap;

// construct min heap
void minHeapify(MinHeap heap, int ind) {
    int min_ind = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    int *arr = heap->array;
    int size = heap->size;

    // select minimal number in root, left, right
    if (left < size && arr[left] < arr[min_ind])
        min_ind = left;
    if (right < size && arr[right] < arr[min_ind])
        min_ind = right;

    if (min_ind != ind) {
        swap(arr[min_ind], arr[ind]);
        minHeapify(heap, min_ind);
    }
}

MinHeap createMinHeap(int *A, int n) {
    MinHeap heap = (MinHeap) malloc(sizeof(min_heap));
    heap->array = A;
    heap->size = n;

    for (int i = (n - 2) / 2; i >= 0; i--) {
        minHeapify(heap, i);
    }

    return heap;
}

MinHeap createMinHeap_deep(int *A, int n) {
    MinHeap heap = (MinHeap) malloc(sizeof(min_heap));
    heap->array = (int *) malloc(sizeof(int) * n);
    heap->size = n;

    for (int i = 0; i < n; i++) {
        heap->array[i] = A[i];
    }

    for (int i = (n - 2) / 2; i >= 0; i--) {
        minHeapify(heap, i);
    }

    return heap;
}

int popMinHeapRoot(MinHeap heap) {
    int *arr = heap->array;
    // get root number
    int n = arr[0];
    swap(arr[0], arr[heap->size - 1]);
    heap->size -= 1;
    minHeapify(heap, 0);
    return n;
}


#endif //DATASTRUCT_MINHEAP_H
