#include<bits/stdc++.h>
using namespace std;
const int MX=100;
//my code
class circular_queue_array
{
private:
    int rear,Front,Length,mxsz;
    int *arraysize;
public:
    circular_queue_array(int Size)
    {
        if (Size<=0)
        {
            mxsz=100;
        }
        else
        {
            mxsz=Size;
        }
        arraysize=new int [mxsz+1];
        Front=0;
        Length=0;
        rear=mxsz-1;
    }
    ~circular_queue_array(){}
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
        if(Length==mxsz)
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
            rear=(rear+1)%mxsz;
            arraysize[rear]=element;
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
            Front=(Front+1)%mxsz;
            Length--;
        }
    }
    int get_front()
    {
        if(IsEmpty())
        {
            return NULL;
        }
        return arraysize[Front];
    }
    int get_rear()
    {
        if(IsEmpty())
        {
            return NULL;
        }
        return arraysize[rear];
    }
    void print()
    {
        if(!IsEmpty())
        {
        for(int i=Front;i!=rear+1;i=(i+1)%mxsz)
        {
            cout<<arraysize[i];
            if(i!=rear)
            {
                cout<<"->";
            }
            else
            {
                break;
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
    int n,x,i;
    cin>>n;
    circular_queue_array q(n);
    for(int i=0;i<n;i++)
    {
        cin>>x;
    q.enqueue(x);
    }
    q.print();
    q.dequeue();
    q.dequeue();
    q.enqueue(123);
    q.print();
    system("pause");


    return 0;
}
