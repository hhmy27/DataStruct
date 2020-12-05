[toc]

Data Struct repo

Something notice and convention:

* `.h` file contains function implementation for convenience
* assume all number which maybe use is `int` type (yes, it is totally a toy project 😂)
* use `CLion 2020.2.3` compile
* compile standard is `c99`



Target:

In This repo, I consider a most simplify implement to common data struct and some algorithm method(like sort)

The following list is the struct of the repo:

(Some of these data structures have not yet been implemented)

## LinkedList

- ListNode

  leetcode style linked list

  you can use it construct linked list to test your algorithm vaild or not

  define:

  ```c
  typedef struct list_node {
      int val;
      struct list_node *next;
  } ListNode;
  ```

  function:

  ```c
  createListNode
  createLinkedList
  visitLinkedList
  ```

  I recommand you use ListNode to quickly construct a linked list

- SingleLinkList

  A single linked list

  define:

  ```c
  typedef struct node {
      int val;
      struct node *next;
  } Node;
  
  typedef struct linked_list {
      Node *head;
      int size;
  } *LinkedList;
  ```

  function:

  ```C
  isEmptyLinkedList
  createEmptyLinkedList
  addLinkedListNodeNum
  reduceLinkedListNodeNum
  insertNodeHeadToLinkedList
  insertNodeTailToLinkedList
  createLinkedListFromArray
  popFrontNodeFromLinkedList
  popTailNodeFromLinkedList
  popNodeFromLinkedListAtPos
  insertNodeToLinkedListBeforePos
  sortLinkedList
  visitLinkedList
  linkedListTransformToArray
  ```

- SingleLinkedListWithTailPointer

  a single linked list with tail pointer

  define:

  ```C
  typedef struct node {
      int val;
      struct node *next;
  } Node;
  
  typedef struct linked_list_with_tail_pointer {
      Node *head;
      int size;
      Node *tail;
  } *LinkedListWithTailPointer;
  ```

  function:

  ```c
  isEmptyLinkedListWithTailPointer
  createEmptyLinkedListWithTailPointer
  addLinkedListWithTailPointerNodeNum
  resetLinkedListWithTailPointerPointer
  reduceLinkedListWithTailPointerNodeNum
  insertNodeHeadToLinkedListWithTailPointer
  insertNodeTailToLinkedListWithTailPointer
  createLinkedListWithTailPointerFromArray
  popFrontNodeFromLinkedListWithTailPointer
  popTailNodeFromLinkedListWithTailPointer
  popNodeFromLinkedListWithTailPointerAtPos
  insertNodeToLinkedListWithTailPointerBeforePos
  sortLinkedListWithTailPointer
  visitLinkedListWithTailPointer
  linkedListWithTailPointerTransformToArray
  ```



## Tree

TODO

## Stack

TODO

## Heap

- MaxHeap

  define:

  ```c
  typedef struct max_heap {
      int size;
      int *array;
  } max_heap, *MaxHeap;
  ```

  function:

  ```c
  maxHeapify
  createMaxHeap
  createMaxHeap_deep
  popMaxHeapRoot
  ```

- MinHeap

  define:

  ```C
  typedef struct min_heap {
      int size;
      int *array;
  } min_heap, *MinHeap;
  ```

  function:

  ```c
  minHeapify
  createMinHeap
  createMinHeap_deep
  popMinHeapRoot
  ```



The following list is the method of the repo:

## Sort

implement 10 sort method in this repo

```c
void bubbleSort(int *A, int n);

void bucketSort(int *A, int n);

void countingSort(int *A, int n);

void doubleBubbleSort(int *A, int n);

void heapSort(int *A, int n);

void insertSort(int *A, int n);

void mergeSort_2(int *A, int n);

void quickSort(int *A, int n);

void radixSort(int *A, int n, int m);

void selectSort(int *A, int n);

void shellSort(int *A, int n);
```

---

Coding style:

* use CLion to format code indent
* use under score case to name variable
* use upper case to name const variable
* use lower camel case to name function
* use lower case and underline to name struct
* use Upper camel case to name variable defined by `typedef`
* function name with `__` denote is private function(for expect) 
* function name with `_` will carry some addition information, like `mergeSort_2` denote it is 2 road merge sort

I make a mind map to help you understand this repo struct

You can check the latest version of the mind map here: [link](https://github.com/hhmy27/myMindMaps/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/DataStructRepo.xmind)

