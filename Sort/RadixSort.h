//
// Created by hmy on 2020/11/21.
//

#ifndef DATASTRUCT_RADIXSORT_H
#define DATASTRUCT_RADIXSORT_H

#include "tool.h"
#include "../List/LinkList/SingleLinkList/SingleLinkList.h"

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


#endif //DATASTRUCT_RADIXSORT_H
