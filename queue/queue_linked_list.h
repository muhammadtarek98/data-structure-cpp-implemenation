#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H
#include<bits/stdc++.h>

class queue_linked_list
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *Front,*rear;
    int Length;
public:
    queue_linked_list();
    bool IsEmpty();
    ~queue_linked_list();
    void enqueue(int element);
    void dequeue();
    int get_front();
    int get_rear();
    void clearr();
    void print();
    int getsize();


};
#endif //QUEUE_LINKED_LIST_H
