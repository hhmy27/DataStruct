//
// Created by hmy on 2020/11/30.
//

#ifndef DATASTRUCT_SINGLELINKEDLIST_H
#define DATASTRUCT_SINGLELINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

// single linked list without dummy head
// this version has tail pointer

typedef struct array {
    int *arr;
    int size;
} *Array;

typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct linked_list {
    Node *head;
    int size;
    Node *tail;
} *LinkedList;

// 1 denote empty
int isEmptyLinkedList(LinkedList L) {
    return L->size == 0;
}

LinkedList createEmptyLinkedList() {
    LinkedList L = (LinkedList) malloc(sizeof(LinkedList));
    L->size = 0;
    L->head = NULL;
    L->tail = NULL;
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
Node *getLinkedListHead(LinkedList L) {
    return L->head;
}


void addNodeNum(LinkedList L) {
    if (!L)
        return;
    L->size += 1;
}

void resetPointer(LinkedList L) {
    L->head = L->tail = NULL;
}


void reduceNodeNum(LinkedList L) {
    if (!L || L->size == 0)
        return;
    L->size -= 1;
    if (L->size == 0) {
        resetPointer(L);
    }
}

// head insert
void insertNodeHead(LinkedList L, int n) {
    if (!L)
        return;
    Node *t = createNodePointer(n);
    t->next = L->head;
    L->head = t;
    if (L->size == 0)
        L->tail = L->head;
    addNodeNum(L);
}

// tail insert
void insertNodeTail(LinkedList L, int n) {
    Node *t = createNodePointer(n);
    if (L->size != 0) {
        Node *tail = L->tail;
        tail->next = t;
    } else {
        L->head = L->tail = t;
    }
    addNodeNum(L);
}

LinkedList createLinkedListFromArray(int *A, int n) {
    LinkedList L = createEmptyLinkedList();
    Node *t = (Node *) malloc(sizeof(Node));
    insertNodeHead(L, A[0]);
    for (int i = 1; i < n; i++) {
        Node *t = (Node *) malloc(sizeof(Node));
        t->val = A[i];
        t->next = NULL;
        L->tail->next = t;
        L->tail = t;
        addNodeNum(L);
    }
    return L;
}

Node *popFrontNode(LinkedList L) {
    if (!L || !L->head)
        return NULL;
    Node *head = L->head;
    // update head node
    L->head = head->next;
    head->next = NULL;
    reduceNodeNum(L);
    return head;
}

int popFrontVal(LinkedList L) {
    return popFrontNode(L)->val;
}

Node *popTailNode(LinkedList L) {
    if (!L || !L->head)
        return NULL;
    if (L->size == 1) {
        return popFrontNode(L);
    } else {
        Node *t = L->head;
        while (t->next != L->tail) {
            t = t->next;
        }
        Node *n = t->next;
        t->next = NULL;
        // update tail
        L->tail = t;
        reduceNodeNum(L);
        return n;
    }
}

Node *popNodeAtPos(LinkedList L, int pos) {
    // empty linked list
    if (!L || !L->head)
        return NULL;
    if (pos == 1)
        return popFrontNode(L);
    if (pos == L->size)
        return popTailNode(L);
    Node *pre = L->head;
    for (int i = 1; i < pos - 1; i++) {
        pre = pre->next;
    }
    Node *n = pre->next;
    pre->next = n->next;
    n->next = NULL;
    reduceNodeNum(L);
    return n;
}

int popTailVal(LinkedList L) {
    return popTailNode(L)->val;
}

// use insert sort to sort link list
// O(nlogn)
void sortLinkedList(LinkedList L) {
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

void visitLinkedList(LinkedList L) {
    Node *t = L->head;
    while (t) {
        printf("%d ", t->val);
        t = t->next;
    }
    printf("\n");
}

Array transformToArray(LinkedList L) {
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

#endif //DATASTRUCT_SINGLELINKEDLIST_H
