//
// Created by hmy on 2020/11/30.
//

#ifndef DATASTRUCT_SINGLELINKEDLISTWITHTAILPOINTER_H
#define DATASTRUCT_SINGLELINKEDLISTWITHTAILPOINTER_H

#include <stdlib.h>
#include <stdio.h>
#include "Node.h"

// single linked list without dummy head
// this version has tail pointer

//typedef struct array {
//    int *arr;
//    int size;
//} *Array;

//typedef struct node {
//    int val;
//    struct node *next;
//} Node;

typedef struct linked_list_with_tail_pointer {
    Node *head;
    int size;
    Node *tail;
} *LinkedListWithTailPointer;

// 1 denote empty
int isEmptyLinkedListWithTailPointer(LinkedListWithTailPointer L) {
    return L->size == 0;
}

LinkedListWithTailPointer createEmptyLinkedListWithTailPointer() {
    LinkedListWithTailPointer L = (LinkedListWithTailPointer) malloc(sizeof(LinkedListWithTailPointer));
    L->size = 0;
    L->head = NULL;
    L->tail = NULL;
    return L;
}


void addLinkedListWithTailPointerNodeNum(LinkedListWithTailPointer L) {
    if (!L)
        return;
    L->size += 1;
}

void resetLinkedListWithTailPointerPointer(LinkedListWithTailPointer L) {
    L->head = L->tail = NULL;
}


void reduceLinkedListWithTailPointerNodeNum(LinkedListWithTailPointer L) {
    if (!L || L->size == 0)
        return;
    L->size -= 1;
    if (L->size == 0) {
        resetLinkedListWithTailPointerPointer(L);
    }
}

// head insert
void insertNodeHeadToLinkedListWithTailPointer(LinkedListWithTailPointer L, int n) {
    if (!L)
        return;
    Node *t = createNodePointer(n);
    t->next = L->head;
    L->head = t;
    if (L->size == 0)
        L->tail = L->head;
    addLinkedListWithTailPointerNodeNum(L);
}

// tail insert
void insertNodeTailToLinkedListWithTailPointer(LinkedListWithTailPointer L, int n) {
    if (!L)
        return;
    Node *t = createNodePointer(n);
    if (L->size != 0) {
        Node *tail = L->tail;
        tail->next = t;
    } else {
        L->head = L->tail = t;
    }
    addLinkedListWithTailPointerNodeNum(L);
}

LinkedListWithTailPointer createLinkedListWithTailPointerFromArray(int *A, int n) {
    LinkedListWithTailPointer L = createEmptyLinkedListWithTailPointer();
    Node *t = (Node *) malloc(sizeof(Node));
    insertNodeHeadToLinkedListWithTailPointer(L, A[0]);
    for (int i = 1; i < n; i++) {
        Node *t = (Node *) malloc(sizeof(Node));
        t->val = A[i];
        t->next = NULL;
        L->tail->next = t;
        L->tail = t;
        addLinkedListWithTailPointerNodeNum(L);
    }
    return L;
}

Node *popFrontNodeFromLinkedListWithTailPointer(LinkedListWithTailPointer L) {
    if (!L || !L->head)
        return NULL;
    Node *head = L->head;
    // update head node
    L->head = head->next;
    head->next = NULL;
    reduceLinkedListWithTailPointerNodeNum(L);
    return head;
}


Node *popTailNodeFromLinkedListWithTailPointer(LinkedListWithTailPointer L) {
    if (!L || !L->head)
        return NULL;
    if (L->size == 1) {
        return popFrontNodeFromLinkedListWithTailPointer(L);
    } else {
        Node *t = L->head;
        while (t->next != L->tail) {
            t = t->next;
        }
        Node *n = t->next;
        t->next = NULL;
        // update tail
        L->tail = t;
        reduceLinkedListWithTailPointerNodeNum(L);
        return n;
    }
}

Node *popNodeFromLinkedListWithTailPointerAtPos(LinkedListWithTailPointer L, int pos) {
    // empty linked list
    if (!L || !L->head)
        return NULL;
    if (pos == 1)
        return popFrontNodeFromLinkedListWithTailPointer(L);
    if (pos == L->size)
        return popTailNodeFromLinkedListWithTailPointer(L);
    Node *pre = L->head;
    for (int i = 1; i < pos - 1; i++) {
        pre = pre->next;
    }
    Node *n = pre->next;
    pre->next = n->next;
    n->next = NULL;
    reduceLinkedListWithTailPointerNodeNum(L);
    return n;
}

void insertNodeToLinkedListWithTailPointerBeforePos(LinkedListWithTailPointer L, int pos, int n) {
    if (isEmptyLinkedListWithTailPointer(L))
        return;
    if (pos == 1) {
        insertNodeHeadToLinkedListWithTailPointer(L, n);
        return;
    }
    if (pos == L->size + 1) {
        insertNodeTailToLinkedListWithTailPointer(L, n);
        return;
    }
    if (pos > L->size + 1)
        return;

    Node *pre = L->head;
    for (int i = 1; i < pos - 1; i++) {
        pre = pre->next;
    }
    Node *t = createNodePointer(n);
    t->next = pre->next;
    pre->next = t;
}

// use insert sort to sort link list
// O(nlogn)
void sortLinkedListWithTailPointer(LinkedListWithTailPointer L) {
    // empty pointer, empty list, just one node list
    if (!L || !L->head || !L->head->next)
        return;

    Node *dummy_head = createNodePointer(-1);
    dummy_head->next = L->head;

    Node *pre = L->head;
    Node *i = pre->next;

    // last node of sorted link list
    Node *last = pre;
    while (i) {
        // already sorted
        if (pre->val <= i->val) {
            pre = pre->next;
            i = i->next;
            continue;
        }
        // execute inside sort
        Node *j;
        if (last->val <= i->val)
            j = last;   // start iterate at last insert node
        else
            j = dummy_head;      // start iterate at first node

        // find need insert palace
        while (j->next->val <= i->val)
            j = j->next;

        // execute insert
        pre->next = i->next;
        i->next = j->next;
        j->next = i;
        last = i;
        i = pre->next;
    }

    L->head = dummy_head->next;
    L->tail = pre;
    dummy_head->next = NULL;
    free(dummy_head);

}

void visitLinkedListWithTailPointer(LinkedListWithTailPointer L) {
    Node *t = L->head;
    while (t) {
        printf("%d ", t->val);
        t = t->next;
    }
    printf("\n");
}

Array linkedListWithTailPointerTransformToArray(LinkedListWithTailPointer L) {
    Array a = (Array) malloc(sizeof(struct array));
    a->arr = (int *) malloc(sizeof(int) * L->size);
    a->size = L->size;
    Node *t = L->head;
    int i = 0;
    while (t) {
        a->arr[i++] = t->val;
        t = t->next;
    }
    return a;
}

#endif //DATASTRUCT_SINGLELINKEDLISTWITHTAILPOINTER_H
