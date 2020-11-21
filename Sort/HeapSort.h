//
// Created by hmy on 2020/11/21.
//

#ifndef DATASTRUCT_HEAPSORT_H
#define DATASTRUCT_HEAPSORT_H

#include "../Heap/MaxHeap.h"

void heapSort(int *A, int n) {
    // shallow copy, O(n)
    MaxHeap heap = createMaxHeap(A, n);

    for (int i = 0; i < n; i++) {
        // max number swap to tail
        int temp = heap->array[0];
        heap->array[0] = heap->array[heap->size - 1];
        heap->array[heap->size - 1] = temp;
        heap->size -= 1;
        // O(logn)
        maxHeapify(heap, 0);
    }
}

#endif //DATASTRUCT_HEAPSORT_H
