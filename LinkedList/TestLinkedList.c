//
// Created by hmy on 2020/12/5.
//

#include "ListNode.h"

int main() {
    int A[] = {1, 2, 3, 4};
    ListNode *head = createLinkedList(A, sizeof(A) / sizeof(int));
    visitLinkedList(head);
}
