#include"Stack_array.h"
using namespace std;
stk_Arry::~stk_Arry(){}
stk_Arry::stk_Arry()
    {
        top=-1;
    }
void stk_Arry::push(int element)
{
    if(top>=MX-1)
    {
        cout<<"Full stack";
    }
    else
    {
    top++;
    item[top]=element;
    }
}
bool stk_Arry::IsEmpty()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void stk_Arry::pop()
{
    if (IsEmpty())
    {
        cout<<"stack is empty";
    }
    else
    {
    top--;
    }
}
void stk_Arry::print()
{
    cout<<"[ ";
    for(int i=top;i>=0;i--)
    {
        cout<<item[i]<<" ";
    }
    cout<<"]"<<endl;
}
int stk_Arry::gettop()
{
    if(IsEmpty())
    {
        cout<<"stack is empty";
    }
    else
    {
        return item[top];
    }
}

void stk_Arry::pop(int &element)
{
    if (IsEmpty())
    {
        cout<<"stack is empty";
    }
    else
    {
        element=item[top];
        top--;
    }
}
int main()
{
    stk_Arry s;
    s.push(2);
    s.push(23);
    s.push(231);
    s.print();
    cout<<endl;
    int x=s.gettop();
    cout<<x;
    s.pop();
      cout<<endl;
     s.print();
    cout<<endl;
    x=s.gettop();
    cout<<x;

    return 0;
}
