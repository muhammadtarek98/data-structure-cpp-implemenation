#include<bits/stdc++.h>
using namespace std;
//my code
class linked_list
{
private:
  struct node
  {
    int item;
    node *next;
  };
  node *first,*last;
  int length;
public:
  linked_list()
  {
    first=NULL;
    last=NULL;
    length=0;
  }
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
      newnode->next=NULL;
    }
    else
    {
      newnode->next=first;
      first=newnode;
    }
    length++;
  }
  void insertlast(int element)
  {
    node *newnode=new node();
    newnode->item=element;
    if(length==0)
    {
      first=last=newnode;
      newnode->next=NULL;
    }
    else
    {
      last->next=newnode;
      newnode->next=NULL;
      last=newnode;
    }
    length++;
  }
  void insertAtPos(int pos,int element)
  {
    if(pos<0||pos>length)
    {
      cout<<"Out of range"<<endl;
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
        cur->next=newnode;
      }
    }
    length++;
  }
  void print()
  {
    node *cur=first;
    while (cur!=NULL)
    {
      cout<<cur->item;
      if(cur->next!=NULL)
      {cout<<"->";}
      cur=cur->next;
    }
  }
  int sz()
  {
      return length;
  }
  void removefront()
  {
    if(length==0||IsEmpty())
    {
      cout<<"List empty"<<endl;
      return;
    }
    else if(length==1)
    {
      delete first;
      first=last=NULL;
    }
    else
    {
      node *temp=first;
      first=first->next;
      delete temp;
    }
    length--;
  }
  int searchelement(int element)
 {
     node *cur=first;
     int pos=0;
     while (cur!=NULL)
     {

       if(cur->item==element)
       {
         return pos;
         break;
       }
       cur=cur->next;
       pos++;
     }
     return -1;
 }
  void removeend()
  {
    node *cur=first->next;
    node *prev=first;
    if(length==0)
    {
      cout<<"List empty"<<endl;
      return;
    }
    else if(length==1)
    {
      delete last;
      first=last=NULL;
    }
    else
    {
      while (cur!=last)
      {
        prev=cur;
        cur=cur->next;
      }
      delete cur;
      last=prev;
    }
    length--;
  }
  void removepos(int element)
  {
    node *cur,*prev;
    if(length==0)
    {
      cout<<"List empty"<<endl;
      return;
    }
    if(first->item==element)
    {
      cur=first;
      first=first->next;
      delete cur;
      if(length==0)
      {
        last=NULL;
      }
    }
    else
    {
      cur=first->next;
      prev=first;
      while (cur!=NULL) {
        if(cur->item==element)
        {
          break;
        }
        prev=cur;
        cur=cur->next;
      }
      if(cur==NULL)
      {
        cout<<"element isn't found"<<endl;
        return;
      }
      else
      {
        prev->next=cur->next;
        if(cur==last)
        {
          last=prev;
        }
        delete cur;
      }
    }
    length--;
  }
  void reverses()
  {
    node *prev=NULL,*cur=first,*nxt;
    nxt=cur->next;
    while(nxt!=NULL)
    {
      nxt=cur->next;
      cur->next=prev;
      prev=cur;
      cur=nxt;
    }
    first=prev;
  }
  ~linked_list()
  {
  }
};
int main()
{
    linked_list l;
    l.insertfirst(21);
    l.insertlast(34);
    l.insertlast(16);
    l.print();
    cout<<" size ="<<l.sz();
    cout<<endl;
    l.reverses();
    l.print();
    cout<<endl;
    cout<<l.searchelement(56);
  return 0;
}
