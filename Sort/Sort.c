//
// Created by hmy on 2020/11/29.
//

#include "Sort.h"
#include "../List/LinkList/SingleLinkList/SingleLinkList.h"
#include "../Heap/MaxHeap.h"

void bubbleSort(int *A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) swap(A[j], A[j + 1]);
        }
    }
}

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
        Array a = (Array) transformToArray(buckets[i]);
        int *arr = a->arr;
        for (int j = 0; j < a->size; j++) {
            A[ind++] = arr[j];
        }
    }
}

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
    for (int i = 0; i < max - min + 1; i++) {
        C[i] = 0;
    }

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

void doubleBubbleSort(int *A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) swap(A[j], A[j + 1]);
        }
        for (int k = n - i - 1; k > i; k--) {
            if (A[k] < A[k - 1]) swap(A[k], A[k - 1]);
        }
    }
}

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

void insertSort(int *A, int n) {
    for (int i = 1; i < n; i++) {
        int v = A[i];
        int j = i - 1;
        for (; j >= 0 && A[j] >= v; j--)
            A[j + 1] = A[j];
        A[j + 1] = v;
    }
}

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

void mergeSort_2__(int *A, int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort_2__(A, left, mid);
    mergeSort_2__(A, mid + 1, right);
    merge(A, left, mid, right);
}


void mergeSort_2(int *A, int n) {
    mergeSort_2__(A, 0, n - 1);
}

void quickSort__(int *A, int left, int right) {
    if (left >= right)
        return;
    int val = A[left];
    int i = left, j = right;
    while (i < j) {
        for (; i < j && A[j] >= val; j--);
        A[i] = A[j];
        for (; i < j && A[i] <= val; i++);
        A[j] = A[i];
    }
    A[i] = val;
    quickSort__(A, left, i - 1);
    quickSort__(A, i + 1, right);
}

void quicksort(int *A, int n) {
    quickSort__(A, 0, n - 1);
}

int getNumInPos(int num, int pos) {
    while (--pos) {
        num /= 10;
    }
    return num % 10;
}

// n is length , m is max length of number
void radixSort(int *A, int n, int m) {
    const int BASE = 10;
    // 10 base
    LinkList container[10];
    for (int i = 0; i < BASE; i++) {
        container[i] = createEmptyLinkList();
    }
    // process all position
    for (int i = 1; i <= m; i++) {
        // process all number in given position
        for (int j = 0; j < n; j++) {
            // get current number
            int tmp = A[j];
            // insert to corresponding contain
            insertNodeTail(container[getNumInPos(tmp, i)], tmp);
        }
        // gather number in contain
        int ind = 0;
        for (int k = 0; k < BASE; k++) {
            while (!isEmptyLinkList(container[k]))
                A[ind++] = popFrontVal(container[k]);
        }
    }
}

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

