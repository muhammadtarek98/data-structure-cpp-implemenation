#include"queue_linked_list.h"
using namespace std;
queue_linked_list::queue_linked_list()
{
    Front=rear=NULL;
    Length=0;
}
queue_linked_list::~queue_linked_list()
{}
bool queue_linked_list::IsEmpty()
{
    if(Front==NULL&&rear==NULL&&Length==0)
    {
        return true;
    }
    return false;
}
void queue_linked_list::enqueue(int element)
{
    if(IsEmpty())
    {
        Front=new node;
        Front->item=element;
        Front->next=NULL;
        rear=Front;
        Length++;
    }
    else
    {
        node *nextelement=new node;
        nextelement->item=element;
        nextelement->next=NULL;
        rear->next=nextelement;
        rear=nextelement;
        Length++;
    }

}
void queue_linked_list::dequeue()
{
    node *temp=new node;
    if(IsEmpty())
        {
            cout<<"Queue is empty"<<endl;
        }
    else if(Length==1)
     {
        Front=NULL;
        rear=NULL;
        Length--;
     }
    else
        {
         temp=Front;
         Front=Front->next;
         temp->next=NULL;
         Length--;
         delete temp;
        }
    }
int queue_linked_list::get_front()
{
    if(IsEmpty())
    {
        cout<<"queue empty"<<endl;
        return 0;
    }
    return Front->item;
}
int queue_linked_list::get_rear()
{
    if(IsEmpty())
    {
        cout<<"queue empty"<<endl;
        return 0;
    }
    return rear->item;
}
void queue_linked_list::clearr()
{
    node *cur;
    while(Front!=NULL)
    {
        cur=Front;
        Front=Front->next;
        delete cur;
    }
    rear =NULL;
    Length=0;
}
void queue_linked_list::print()
{
    node *cur=Front;
    while(cur!=NULL)
    {
        cout<<cur->item;
        if(cur->next!=NULL)
        {
            cout<<"->";
        }
        cur=cur->next;
    }
}
int queue_linked_list::getsize()
{
    return Length;
}
int main()
{
 queue_linked_list q;
 q.enqueue(12);
 q.enqueue(23);
 q.enqueue(32);
 q.enqueue(45);
 q.print();
 cout<<endl;
 cout<<q.get_front()<<endl;
 cout<<q.get_rear()<<endl;
 cout<<q.getsize()<<endl;
 q.dequeue();
 q.print();
 cout<<endl;
  cout<<q.get_front()<<endl;
 cout<<q.get_rear()<<endl;
 cout<<q.getsize()<<endl;
 q.clearr();
cout<<q.get_front()<<endl;
 cout<<q.get_rear()<<endl;
 cout<<q.getsize()<<endl;
    return 0;
}
