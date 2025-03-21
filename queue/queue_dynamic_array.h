#ifndef QUEUE_DYNAMIC_ARRAY_H
#define QUEUE_DYNAMIC_ARRAY_H
#include <bits/stdc++.h>
class arrayQueueType
{
    int rear;
    int Front;
    int length;
    int *arr;
    int maxSize;

public:
    arrayQueueType(int size);
    int isEmpty();
    bool isFull();
    void addQueue(int Element);
    void deleteQueue();
    int frontQueue();
    int rearQueue();
    void printQueue();
    int queueSearch(int element);
    ~arrayQueueType();
};
#endif //QUEUE_DYNAMIC_ARRAY_H
