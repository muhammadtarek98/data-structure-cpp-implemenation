
#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#include <bits/stdc++.h>
const int MX=100;

class stk_Arry
{
private:
    int top;
    int item[MX];
public:
    ~stk_Arry();
    stk_Arry();
    void push(int element);
    bool IsEmpty();
    void pop();
    void print();
    int gettop();
    void pop(int &element);

};
#endif //STACK_ARRAY_H
