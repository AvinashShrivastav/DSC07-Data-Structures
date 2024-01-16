#include <iostream>
using namespace std;

class queue
{
    private:
    int* Array;
    int frnt;
    int rear;
    int size = 0;
    int noe;

    public:
    queue(int s)
    {
        size = s;
        Array = new int[size];
        frnt = 0;
        rear = 0;
        noe = 0;


    }
    int NumOfEle()
    {
        return noe;
    }
    bool empty()
    {
        return noe == 0;
    }
    int& front()
    {
        if(empty())
        {
            cout<<"Queue is empty"<<endl;
        }
        else{
return Array[frnt];
        }
        
    }
    void dequeue()
    {
        if( empty())
        {
            cout<<"Empty Queue"<<endl;
        }
        else{
            frnt = (frnt+1)%size;
            noe = noe-1;
        }
    }
    void enqueue(int num)
    {
        if (NumOfEle() == size )
        {
            cout<<"Full Stack"<<endl;
        }
        else{
            Array[rear] = num;
            rear = (rear+1)%size;
            noe++;

        }
        
    }
    void print()
    {
        int i = frnt;
       while(i != rear )
       {
        cout<<Array[i]<<" ";
        i = (i+1)%size;
       }
       cout<<endl;
    }



};

int main()
{
    queue A(10);
    cout<<A.NumOfEle()<<endl;
    A.enqueue(10);
    A.enqueue(20);
    A.enqueue(30);
    A.print();
    A.dequeue();
    A.dequeue();
    A.print();
    A.dequeue();
    A.print();
    A.dequeue();
    A.print();


}
