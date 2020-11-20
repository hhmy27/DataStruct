cmake_minimum_required(VERSION 3.17)
project(DataStruct C)

set(CMAKE_C_STANDARD 99)
aux_source_directory(./Sort FILES_SORT)

add_executable(DataStruct ${FILES_SORT} Sort/BubbleSort.h Sort/DoubleBubbleSort.h Sort/InsertSort.h Sort/SelectSort.h Sort/MergeSort_2.h Sort/MergeSort_n.h Sort/ShellSort.h Sort/CountingSort.h Sort/BucketSort.h List/LinkList/SingleLinkList/SingleLinkList.h List/SequenceList/SequenceList.h)