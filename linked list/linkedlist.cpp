#include"linkedlist.h"
linked_list::linked_list()
{
  first=NULL;
  last=NULL;
  length=0;
}
bool linked_list::IsEmpty()
{
  if(length==0)
  {
    return true;
  }
  return false;
}
void linked_list::insertfirst(int element)
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
void linked_list::insertlast(int element)
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
void linked_list::insertAtPos(int pos,int element)
{
  if(pos<0||pos>length)
  {
    std::cout<<"Out of range"<<std::endl;
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
void linked_list::print()
{
  node *cur=first;
  while (cur!=NULL)
  {
    std::cout<<cur->item;
    if(cur->next!=NULL)
    {std::cout<<"->";}
    cur=cur->next;
  }
}
int linked_list::sz()
{
    return length;
}
void linked_list::removefront()
{
  if(length==0||IsEmpty())
  {
    std::cout<<"List empty"<<std::endl;
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
int linked_list::searchelement(int element)

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

void linked_list::removeend()
{
  node *cur=first->next;
  node *prev=first;
  if(length==0)
  {
    std::cout<<"List empty"<<std::endl;
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
void linked_list::removepos(int element)
{
  node *cur,*prev;
  if(length==0)
  {
    std::cout<<"List empty"<<std::endl;
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
      std::cout<<"element isn't found"<<std::endl;
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
void linked_list::reverses()
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
linked_list::~linked_list()
{
}

int main()
{
    linked_list l;
    l.insertfirst(21);
    l.insertlast(34);
    l.insertlast(16);
    l.print();
    std::cout<<" size ="<<l.sz();
    std::cout<<std::endl;
    l.reverses();
    l.print();
    std::cout<<std::endl;
    std::cout<<l.searchelement(56);
  return 0;
}
