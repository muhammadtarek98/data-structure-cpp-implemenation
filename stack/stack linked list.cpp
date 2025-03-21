#include<bits/stdc++.h>
using namespace std;
const int MX=100;
//my code
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
    stk_linked_list()
    {
        top=NULL;
    }
    ~stk_linked_list()
    {}
    void push(int element)
    {
        node *newitemptr=new node;
        if(newitemptr==NULL)
        {
            cout<<"Can't allocate memory";
        }
        else
        {
            newitemptr->item=element;
            newitemptr->next=top;
            top=newitemptr;
        }
    }
    bool IsEmpty()
    {
        if (top==NULL)
            return true;
        return false;
    }
    void pop()
    {
        if(IsEmpty())
        {
            cout<<"stack empty";
        }
        else
        {
            node *temp=new node;
            temp=top;
            top=top->next;
            temp=temp->next=NULL;
            delete temp;
        }
    }
     int get_top()
    {
        if(IsEmpty())
        {
            cout<<"stack empty";
            return 0;
        }
       return top->item;
    }
    void print()
    {
        current=top;
        while (current!=NULL)
        {
            cout<<current->item;
            if(current->next!=NULL)
            {
                cout<<"->";
            }
             current=current->next;


        }
    }

};
int main()
{
    stk_linked_list s;
    int n;
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    s.print();

    return 0;
}
