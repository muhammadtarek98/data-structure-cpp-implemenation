#include"stack_linked_list.h"
using namespace std;
//my code
stk_linked_list::stk_linked_list()
    {
        top=NULL;
    }
stk_linked_list::~stk_linked_list()
{}
void stk_linked_list::push(int element)
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
bool stk_linked_list::IsEmpty()
{
    if (top==NULL)
        return true;
    return false;
}
void stk_linked_list::pop()
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
 int stk_linked_list::get_top()
{
    if(IsEmpty())
    {
        cout<<"stack empty";
        return 0;
    }
   return top->item;
}
void stk_linked_list::print()
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
