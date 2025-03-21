#include<bits/stdc++.h>
#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H
template<class t>
class linkedQueue
{
private:
    struct Node
    {
        t item;
        Node *next;
    };
    int length;
    Node *frontPtr, *rearPtr;

public:

    linkedQueue();
    ~linkedQueue();
    bool isEmpty();
    void dequeue();
    void enqueue(t item);
    t front();
    t rear();
    void clearQueue();
    void display();
    void search(t item);

};
#endif //QUEUE_LIST_H
