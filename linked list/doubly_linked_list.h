#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include<bits/stdc++.h>
class doubly_linkedlist
{
private:
    struct node{
        int item;
        node *prev,*next;
    };
    node *first,*last;
    int length;
public:
    doubly_linkedlist();
    ~doubly_linkedlist();
    bool IsEmpty();
    void insertfirst(int element);
    void insertlast(int element);
    void insertAt(int pos,int element);
    void removefront();
    void removeend();
    void removeAt(int element);
    void print();
    void reverseprint();

};
#endif //DOUBLY_LINKED_LIST_H
