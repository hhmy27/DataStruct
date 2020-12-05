//
// Created by hmy on 2020/12/5.
//

#ifndef DATASTRUCT_LISTNODE_H
#define DATASTRUCT_LISTNODE_H

#include <stdio.h>
#include <stdlib.h>

// leetcode style linked list
typedef struct list_node {
    int val;
    struct list_node *next;
} ListNode;

ListNode *createListNode(int v) {
    ListNode *t = (ListNode *) malloc(sizeof(ListNode));
    t->val = v;
    t->next = NULL;
    return t;
}

ListNode *createLinkedList(int *A, int n) {
    ListNode *head = createListNode(A[0]);
    ListNode *tail = head;
    for (int i = 1; i < n; i++) {
        ListNode *t = createListNode(A[i]);
        tail->next = t;
        tail = t;
    }
    return head;
}

void visitLinkedList(ListNode *head) {
    printf("linked list(head at %p): ", head);
    while (head) {
        printf("%d%s", head->val, head->next != NULL ? "->" : "");
        head = head->next;
    }
}


#endif //DATASTRUCT_LISTNODE_H
