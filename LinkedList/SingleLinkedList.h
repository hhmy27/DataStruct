//
// Created by hmy on 2020/12/1.
//

#ifndef DATASTRUCT_SINGLELINKEDLIST_H
#define DATASTRUCT_SINGLELINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

#include "Node.h"

// Single link list has head node which store the number of node
// this version has not tail pointer, so operate at tail will iterate all link list
// L is head node,L->next is first node

//typedef struct node {
//    int val;
//    struct node *next;
//} Node, HeadNode, *LinkList;


typedef struct linked_list {
    Node *head;
    int size;
} *LinkedList;


// 1 denote empty
int isEmptyLinkedList(LinkedList L) {
    if (!L || !L->head)
        return 1;
    return L->size == 0;
}

LinkedList createEmptyLinkedList() {
    LinkedList L = (LinkedList) malloc(sizeof(struct linked_list));
    L->size = 0;
    L->head = NULL;
    return L;
}

void addLinkedListNodeNum(LinkedList L) {
    if (!L)
        return;
    L->size += 1;
}

void reduceLinkedListNodeNum(LinkedList L) {
    if (!L)
        return;
    L->size -= 1;
}

// head insert
void insertNodeHeadToLinkedList(LinkedList L, int n) {
    if (!L)
        return;
//    Node *t = (Node *) malloc(sizeof(Node));
    Node *t = createNodePointer(n);
    if (L->head == NULL) {
        L->head = t;
    } else {
        t->next = L->head;
        L->head = t;
    }
    addLinkedListNodeNum(L);
}

// tail insert
void insertNodeTailToLinkedList(LinkedList L, int n) {
    if (!L || !L->head)
        return;
    Node *t = createNodePointer(n);
    Node *tail = L->head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = t;
    addLinkedListNodeNum(L);
}

LinkedList createLinkedListFromArray(int *A, int n) {
    LinkedList L = createEmptyLinkedList();
    L->size = n;
    insertNodeHeadToLinkedList(L, A[0]);
    Node *tail = L->head;
    for (int i = 1; i < n; i++) {
        Node *t = createNodePointer(A[i]);
        tail->next = t;
        tail = t;
    }
    return L;
}


Node *popFrontNodeFromLinkedList(LinkedList L) {
    if (!L || !L->head)
        return NULL;
    Node *head = L->head;
    L->head = head->next;
    head->next = NULL;
    reduceLinkedListNodeNum(L);
    return head;
}


Node *popTailNodeFromLinkedList(LinkedList L) {
    if (!L || !L->head)
        return NULL;
    Node *tail = L->head;
    while (tail->next) {
        tail = tail->next;
    }
    Node *t = tail->next;
    tail->next = NULL;
    reduceLinkedListNodeNum(L);
    return t;
}

Node *popNodeFromLinkedListAtPos(LinkedList L, int pos) {
    // empty linked list
    if (isEmptyLinkedList(L))
        return NULL;
    if (pos == 1)
        return popFrontNodeFromLinkedList(L);
    if (pos == L->size)
        return popTailNodeFromLinkedList(L);
    Node *pre = L->head;
    for (int i = 1; i < pos - 1; i++) {
        pre = pre->next;
    }
    Node *n = pre->next;
    pre->next = n->next;
    n->next = NULL;
    reduceLinkedListNodeNum(L);
    return n;
}

// insert node at before pos
//    L: 1->2->3, insert(L,1,-2)
// => L: -2->1->2->3
//    L: 1->2->3, insert(L,1,3)
// => L: 1->2->3->-2
void insertNodeToLinkedListBeforePos(LinkedList L, int pos, int n) {
    if (isEmptyLinkedList(L))
        return;
    if (pos == 1) {
        insertNodeHeadToLinkedList(L, n);
        return;
    }
    if (pos == L->size + 1) {
        insertNodeTailToLinkedList(L, n);
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
void sortLinkedList(LinkedList L) {
    // empty pointer, empty list, just one node list
    if (!L || !L->head || !L->head->next)
        return;
    Node *dummy_head = createNodePointer(-1);
    dummy_head->next = L->head;
    // first node is head next
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

Array linkedListTransformToArray(LinkedList L) {
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
