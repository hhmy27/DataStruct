//
// Created by hmy on 2020/11/20.
//

#ifndef DATASTRUCT_SINGLELINKLIST_H
#define DATASTRUCT_SINGLELINKLIST_H

#include <stdlib.h>
#include <stdio.h>

// Single link list has head node which store the number of node
// this version has not tail pointer, so operate at tail will iterate all link list
// L is head node,L->next is first node

typedef struct node {
    int val;
    struct node *next;
} Node, HeadNode, *LinkList;

typedef struct array {
    int *arr;
    int size;
} *Array;

// 1 denote empty
int isEmptyLinkList(LinkList L) {
    return L->val == 0;
}

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


LinkList createLinkListFromArray(int *A, int n) {
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
    return L;
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

Node *popFrontNode(LinkList L) {
    if (!L || !L->next)
        return NULL;
    Node *head = getLinkListHead(L);
    Node *t = head->next;
    head->next = head->next->next;
    reduceNodeNum(L);
    return t;
}

int popFrontVal(LinkList L) {
    return popFrontNode(L)->val;
}

Node *popTailNode(LinkList L) {
    if (!L || !L->next)
        return NULL;
    Node *tail = getLinkListHead(L);
    while (tail->next) {
        tail = tail->next;
    }
    Node *t = tail->next;
    tail->next = tail->next->next;
    reduceNodeNum(L);
    return t;
}

int popTailVal(LinkList L) {
    return popTailNode(L)->val;
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

void visitLinkList(LinkList L) {
    Node *head = getLinkListHead(L);
    Node *t = head->next;
    while (t) {
        printf("%d ", t->val);
        t = t->next;
    }
}

Array transformToArray(LinkList L) {
    Array a = (Array) malloc(sizeof(struct array));
    a->arr = (int *) malloc(sizeof(int) * L->val);
    a->size = L->val;
    Node *t = L->next;
    int i = 0;
    while (t) {
        a->arr[i++] = t->val;
        t = t->next;
    }
    return a;
}


#endif //DATASTRUCT_SINGLELINKLIST_H
