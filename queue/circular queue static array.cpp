#include<bits/stdc++.h>
using namespace std;
const int MX=100;
//my code
class circular_queue_array
{
private:
    int rear,Front,Length;
    int Queue[MX];
public:
    circular_queue_array()
    {
        Front=0;
        Length=0;
        rear=MX-1;
    }
    ~circular_queue_array()
    {}
    bool IsEmpty()
    {
        if(Length==0)
        {
            return true;
        }
        return false;
    }
    bool IsFull()
    {
        if(Length==MX)
        {
            return true;
        }
        return false;
    }
    void enqueue(int element)
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
    void dequeue()
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
    int get_front()
    {
        if(IsEmpty())
        {
            return NULL;
        }
        return Queue[Front];
    }
    int get_rear()
    {
        if(IsEmpty())
        {
            return NULL;
        }
        return Queue[rear];
    }
    void print()
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

};
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
