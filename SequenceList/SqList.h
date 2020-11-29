//
// Created by hmy on 2020/11/20.
//

#ifndef DATASTRUCT_SEQUENCELIST_H
#define DATASTRUCT_SEQUENCELIST_H

#include <stdlib.h>
#include <string.h>

//typedef struct array {
//    int size;
//    int *arr;
//} *Array;

typedef struct sequence_list {
    // max size
    int length;
    // practical size
    int size;
    int *arr;
} sequence_list, *SqList;

SqList createEmptySqList() {
    SqList L = (SqList) malloc(sizeof(struct sequence_list));
    L->arr = NULL;
    L->length = 0;
    L->size = 0;
    return L;
}


int getSqListSize(SqList L) {
    return L->size;
}

int getSqListLength(SqList L) {
    return L->length;
}

int isFullSqList(SqList L) {
    return getSqListLength(L) == getSqListSize(L);
}

// create SqList from array， is deep copy
SqList createSqListFromArray(int *A, int n) {
    SqList L = createEmptySqList();
    L->length = 2 * n;
    L->size = n;
    L->arr = (int *) malloc(sizeof(int) * L->length);
    memset(L->arr, 0, L->length);
    for (int i = 0; i < n; i++) {
        L->arr[i] = A[i];
    }
    return L;
}

void addSize(SqList L) {
    if (!L)
        return;
    L->size += 1;
}

void reduceSize(SqList L) {
    if (!L)
        return;
    L->size -= 1;
}

void enlargeSqListArray(SqList L) {
    if (!L)
        return;
    L->length *= 2;
    int *t = L->arr;
    free(L->arr);
    L->arr = (int *) malloc(sizeof(int) * L->length);
    memset(L->arr, 0, L->size);
    for (int i = 0; i < L->size; i++) {
        L->arr[i] = t[i];
    }
}

void append(SqList L, int n) {
    if (!L)
        return;
    if (isFullSqList(L))
        enlargeSqListArray(L);
    L->arr[L->size] = n;
    addSize(L);
}



//// return deep copy of L
//Array getArray(SqList L) {
//    Array a = (Array) malloc(sizeof(Array));
//    a->arr = (int *) malloc(sizeof(int) * L->size);
//    for (int i = 0; i < L->size; i++) {
//        a->arr[i] = L->arr[i];
//    }
//    return a;
//}

#endif //DATASTRUCT_SEQUENCELIST_H
