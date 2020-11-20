//
// Created by hmy on 2020/11/20.
//

#ifndef DATASTRUCT_SINGLELINKLIST_H
#define DATASTRUCT_SINGLELINKLIST_H

#include <stdlib.h>

// Single link list has head node which store the number of node
// L is head node,L->next is first node

typedef struct node {
    int val;
    struct node *next;
} Node, HeadNode, *LinkList;

typedef struct array {
    int *arr;
    int size;
} *Array;


LinkList createEmptyLinkList() {
    LinkList L = (LinkList) malloc(sizeof(HeadNode));
    L->val = 0;
    L->next = NULL;
    return L;
}

// create a node by parameter n and return a pointer which point to this new node
Node *createNodePointer(int n) {
    Node *t = (Node *) malloc(sizeof(Node));
    t->next = NULL;
    t->val = n;
    return t;
}

// get head node
Node *getLinkListHead(LinkList L) {
    return L;
}


LinkList createLinkList(int *A, int n) {
    LinkList L = createEmptyLinkList();
    L->val = n;
    Node *tail = L;
    for (int i = 0; i < n; i++) {
        Node *t = (Node *) malloc(sizeof(Node));
        t->val = A[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
}

void addNodeNum(LinkList L) {
    if (!L)
        return;
    L->val += 1;
}

void reduceNodeNum(LinkList L) {
    if (!L)
        return;
    L->val -= 1;
}

// head insert
void insertNodeHead(LinkList L, int n) {
    if (!L)
        return;
//    Node *t = (Node *) malloc(sizeof(Node));
    Node *t = createNodePointer(n);
    t->val = n;
    t->next = L->next;
    L->next = t;
    addNodeNum(L);
}

// tail insert
void insertNodeTail(LinkList L, int n) {
    Node *t = createNodePointer(n);
    Node *tail = getLinkListHead(L);
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = t;
    addNodeNum(L);
}

// use insert sort to sort link list
// O(nlogn)
void sortLinkList(LinkList L) {
    // empty pointer, empty list, just one node list
    if (!L || !L->next || !L->next->next)
        return;
    // first node is head next
    Node *first = L->next;
    Node *pre = first;
    Node *i = pre->next;
    // last node of sorted link list
    Node *last = first;
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
            j = L;      // start iterate at first node

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
}

Array transformToArray(LinkList L) {
    Array a = (Array) malloc(sizeof(Array));
    a->arr = (int *) malloc(sizeof(int) * L->val);

    return a;
}


#endif //DATASTRUCT_SINGLELINKLIST_H
