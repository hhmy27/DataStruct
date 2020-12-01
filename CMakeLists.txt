cmake_minimum_required(VERSION 3.17)
project(DataStruct C)

set(CMAKE_C_STANDARD 99)

#add_executable(DataStruct Sort/main.c Sort/Sort.h Sort/Sort.c)

add_executable(DataStruct Sort/main.c LinkedList/DoubleLinkedList.h LinkedList/SingleLinkedList.h LinkedList/Node.h LinkedList/SingleLinkedListWithTailPointer.h)
