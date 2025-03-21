#include<bits/stdc++.h>
using namespace std;
const int MX=100;
//my code
class stk_Arry
{
private:
    int top;
    int item[MX];
public:
  ~stk_Arry()
  {}
    stk_Arry()
    {
        top=-1;
    }
   void push(int element)
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
    bool IsEmpty()
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
    void pop()
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
    void print()
    {
        cout<<"[ ";
        for(int i=top;i>=0;i--)
        {
            cout<<item[i]<<" ";
        }
        cout<<"]"<<endl;
    }
    int gettop()
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

    void pop(int &element)
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

};
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
