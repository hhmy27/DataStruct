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

int main() {
    int A[] = {5, 1, 3, 4, 2};
//    bubbleSort(A, len(A));
//    doubleBubbleSort(A, len(A));
//    insertSort(A, len(A));
//    selectSort(A, len(A));
//    mergeSort_2(A, len(A));
//    mergeSort_2(A, len(A));
//    shellSort(A,len(A));
    countingSort(A, len(A));
    visitArray(A);
}
