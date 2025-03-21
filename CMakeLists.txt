cmake_minimum_required(VERSION 3.30)
project(data_structure_c_implemenation_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories("binary search tree")
include_directories("linked list")
include_directories(queue)
include_directories(stack)

add_executable(data_structure_c_implemenation_
    "binary search tree/binary_search_tree.cpp"
        "linked list/doubly linked list.cpp"
    "linked list/doubly linked list2.cpp"
    "linked list/linkedlist.cpp"
    "linked list/listSTL.cpp"
    "queue/circular queue dynamic array.cpp"
    "queue/circular queue static array.cpp"
    "queue/queue list.cpp"
    queue/queue_dynamic_array.cpp
    queue/queue_linked_list.cpp
    "stack/Stack array.cpp"
    "stack/stack linked list.cpp"
    heap_sort.cpp
    "pre,in,post order.cpp"
    "tips & tricks .cpp")
