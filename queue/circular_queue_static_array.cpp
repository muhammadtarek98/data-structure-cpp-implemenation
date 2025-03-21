#include"circular_queue_static_array.h"
using namespace std;
//my code
circular_queue_array::circular_queue_array()
{
    Front=0;
    Length=0;
    rear=MX-1;
}
circular_queue_array::~circular_queue_array()
{}
bool circular_queue_array::IsEmpty()
{
    if(Length==0)
    {
        return true;
    }
    return false;
}
bool circular_queue_array::IsFull()
{
    if(Length==MX)
    {
        return true;
    }
    return false;
}
void circular_queue_array::enqueue(int element)
{
    if(IsFull())
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        rear=(rear+1)%MX;
        Queue[rear]=element;
        Length++;
    }
}
void circular_queue_array::dequeue()
{
    if(IsEmpty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        Front=(Front+1)%MX;
        Length--;
    }
}
int circular_queue_array::get_front()
{
    if(IsEmpty())
    {
        return NULL;
    }
    return Queue[Front];
}
int circular_queue_array::get_rear()
{
    if(IsEmpty())
    {
        return NULL;
    }
    return Queue[rear];
}
void circular_queue_array::print()
{
    if(!IsEmpty())
    {
    for(int i=Front;i!=rear+1;i=(i+1)%MX)
    {
        cout<<Queue[i];
        if(i!=rear)
        {
            cout<<"->";
        }
    }
    }
    else
    {
        cout<<"Queue empty";
    }
    cout<<endl;

}
int main()
{
    circular_queue_array cqr;
    cqr.enqueue(12);
    cqr.enqueue(45);
    cqr.enqueue(56);
    cqr.print();
    cqr.dequeue();
    cqr.print();
    system("pause");


    return 0;
}
