//
// Created by hmy on 2020/12/1.
//

#ifndef DATASTRUCT_NODE_H
#define DATASTRUCT_NODE_H

typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct array {
    int *arr;
    int size;
} *Array;

// create a node by parameter n and return a pointer which point to this new node
Node *createNodePointer(int n) {
    Node *t = (Node *) malloc(sizeof(Node));
    t->next = NULL;
    t->val = n;
    return t;
}

#endif //DATASTRUCT_NODE_H
