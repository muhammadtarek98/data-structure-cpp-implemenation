#include<bits/stdc++.h>
using namespace std;
//my code
class doubly_linkedlist
{
private:
  struct node{
    int item;
    node *prev,*next;
  };
  node *first,*last;
  int length;
public:
  doubly_linkedlist()
  {
    first=NULL;
    last=NULL;
    length=0;
  }
  ~doubly_linkedlist()
  {}
  bool IsEmpty()
  {
    if(length==0)
    {
      return true;
    }
    return false;
  }
  void insertfirst(int element)
  {
    node *newnode=new node();
    newnode->item=element;
    if(length==0)
    {
      first=last=newnode;
      newnode->prev=newnode->next=NULL;
    }
    else
    {
      newnode->next=first;
      newnode->prev=NULL;
        first->prev=newnode;
        first=newnode;
    }
    length++;
  }
  void insertlast(int element)
  {
    node *newnode=new node();
    if(length==0)
    {
      first=last=newnode;
      newnode->prev=newnode->next=NULL;
    }
    else
    {
      newnode->next=NULL;
      newnode->prev=last;
      last->next=newnode;
      last=newnode;
    }
    length++;
  }
  void insertAt(int pos,int element)
   {
    if(pos<0||pos>length)
    {
      cout<<"insertion error"<<endl;
      return;
    }
    else
    {
      node *newnode=new node();
      newnode->item=element;
      if(pos==0)
      {
        insertfirst(element);
      }
      else if(pos==length)
      {
        insertlast(element);
      }
      else
      {
        node *cur=first;
        for(int i=1;i<pos;i++)
        {
          cur=cur->next;
        }
        newnode->next=cur->next;
        newnode->prev=cur;
        cur->next=newnode;
        cur->next->prev=newnode;

      }
    }
    length++;
   }
   void removefront()
   {
     if(length==0)
     {
       printf("list empty\n" );
       return;
     }
     else if(length==1)
     {
       delete first;
       first=last=NULL;
     }
     else
     {
       node *cur=first;
       first=first->next;
       first->prev=NULL;
       delete cur;
     }
     length--;
   }
   void removeend()
   {
     if(length==0)
     {
       printf("list empty\n" );
       return;
     }
     else if(length==1)
     {
       delete last;
       first=last=NULL;
     }
     else
     {
       node *cur=last;
       last=last->prev;
       last->next=NULL;
       delete cur;
     }
     length--;
   }
   void removeAt(int element)
    {
      if(length==0)
      {
        printf("list empty\n" );
        return;
      }
      if(first->item==element)
      {
        removefront();
      }
      else
      {
        node *cur=first->next;
        while(cur!=NULL&&cur->item!=element)
        {
          if(cur->item==element)
          {
          break;
          }
          cur=cur->next;
        }
        if(cur==NULL)
        {
          cout<<"not found"<<endl;
        }
        else if(cur->next==NULL)
        {
          removeend();
        }
        else
        {
          cur->prev->next=cur->next;
          cur->next->prev=cur->prev;
          delete cur;
        }
      }
      length--;
    }
    void print()
    {
      node *cur=first;
      while (cur!=NULL)
      {
        cout<<cur->item<<" ";
        cur=cur->next;
      }
    }
    void reverseprint()
    {
      node  *cur=last;
      while (cur != NULL)
      {
        cout<<cur->item<<" ";
        cur=cur->prev;
      }
    }
};
int main()
{

  return 0;
}
