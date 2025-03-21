#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<bits/stdc++.h>
struct node
{
    int item;
    node *next;
};
class linked_list
{
private:

    node *first,*last;
    int length;
public:
    linked_list();
    bool IsEmpty();
    void insertfirst(int element);
    void insertlast(int element);
    void insertAtPos(int pos,int element);
    void print();
    int sz();
    void removefront();
    int searchelement(int element);
    void removeend();
    void removepos(int element);
    void reverses();
    ~linked_list();

};
#endif //LINKEDLIST_H
