//
// Created by hmy on 2020/11/17.
//

#include <stdio.h>
#include "tool.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "DoubleBubbleSort.h"
#include "InsertSort.h"
#include "SelectSort.h"
#include "MergeSort_2.h"
#include "ShellSort.h"
#include "CountingSort.h"
#include "../List/LinkList/SingleLinkList/SingleLinkList.h"
#include "BucketSort.h"

int main() {
    int A[] = {5, 1, 3, 4, 2};
//    bubbleSort(A, len(A));
//    doubleBubbleSort(A, len(A));
//    insertSort(A, len(A));
//    selectSort(A, len(A));
//    mergeSort_2(A, len(A));
//    mergeSort_2(A, len(A));
//    shellSort(A,len(A));
//    countingSort(A, len(A));
//    test LinkList
//    LinkList L = createLinkList(A, len(A));
//    visitLinkList(L);
//    printf("\n");
//    Array a = transformToArray(L);
//    int *arr = a->arr;
//    for (int i = 0; i < a->size; i++) {
//        printf("%d ", *(arr + i));
//    }
    bucketSort(A,len(A));
    visitArray(A);
}
