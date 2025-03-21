#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H
#include <bits/stdc++.h>
const int MX=100;
class stk_linked_list
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *top,*current;
public:
    stk_linked_list();
    ~stk_linked_list();
    void push(int element);
    bool IsEmpty();
    void pop();
    int get_top();
    void print();

};
#endif //STACK_LINKED_LIST_H
