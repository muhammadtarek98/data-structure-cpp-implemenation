#ifndef CIRCULAR_QUEUE_STATIC_ARRAY_H
#define CIRCULAR_QUEUE_STATIC_ARRAY_H
#include<bits/stdc++.h>
const int MX=100;

class circular_queue_array
{
private:
    int rear,Front,Length;
    int Queue[MX];
public:
    circular_queue_array();
    ~circular_queue_array();
    bool IsEmpty();
    bool IsFull();
    void enqueue(int element);
    void dequeue();
    int get_front();
    int get_rear();
    void print();

};
#endif //CIRCULAR_QUEUE_STATIC_ARRAY_H
