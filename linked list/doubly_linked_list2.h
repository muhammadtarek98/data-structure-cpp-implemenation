//
// Created by muhammad on 21/03/25.
//

#ifndef DOUBLY_LINKED_LIST2_H
#define DOUBLY_LINKED_LIST2_H
#include<bits/stdc++.h>
class doublyLinkedList2 {
private:
    struct Node {
        int item;
        Node* next;
        Node* prev;
    };
    Node* first;
    Node* last;
    int count;

public:
    doublyLinkedList2();
    bool isEmpty();
    void destroy();
    void insertLast(int val);
    void insertFirst(int item);
    void insertAt(int pos, int item);
    void removeFirst();
    void deleteNthNode(int pos);
    void removeLast();
    void remove(int item);
    void display() ;
    void reverse_display();

};
#endif //DOUBLY_LINKED_LIST2_H
