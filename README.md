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

- **Tree**

  - BinaryTree
  - AVLTree

- **LinkedListWithTailPointer**

  All `LinkedListWithTailPointer` will have a head node that save the number of node in this link list

  - SingleLinkList

    A single link list with have tail pointer

  - DoubleLinkList

    A double link list with have tail pointer

- **SequenceList**

  - SqList

    SqList has fixed length,  but it can enlarge or reduce length

- **Stack**

  just a stack implemented by link list

- **Deque**

  A deque implemented by double link list

The following list is the method of the repo:

- Sort

  implement 10 sort method in this repo

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

