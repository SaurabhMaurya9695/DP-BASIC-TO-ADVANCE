#include<bits/stdc++.h>
using namespace std;

class Queue
{
    public:
        int size;
        int front;
        int rear;
        int *arr;
        
    // constrcutor
    Queue(int n)
    {
        this->size = n;
        this->rear = 0;
        this->front = 0;
        this-> arr = new int[n];
    }
    
    void enqueu(int x)
    {
        if(rear + 1 == size)
        {
            cout<<"Queue overflow\n";
            
        }
        else{
            arr[rear] = x;
            rear ++;
        }
    }
    
    int dequeu() // remove
    {
        int x ;
        if(front == rear)
        {
            cout<<"queue underflow\n";
            return -1;
        }
        else {
            x = arr[front];
            for (int i = 0; i < rear - 1; i++) {
                arr[i] = arr[i + 1];
            }
 
            // decrement rear
            rear--;
        }
        return x; 
    }
    
    int back()
    {
        if(rear + 1 == size)
        {
            cout<<"back doesn't exist\n";
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    
    int Front()
    {
        return arr[front];
    }
    
    int Size()
    {
        return rear - front + 1 ;
    }
    
    void display()
    {
        for(int i = front ; i < rear ; i++)
        {
            cout<< arr[front] << " " ;
        }
    }  
    
};



int main()
{
    string s;
    cin>> s;
    Queue q(5);
    while(s != "quit")
    {
        if(s == "insert") // insert
        {
            int x;
            cin>> x;
            q.enqueu(x);
        }
        else if(s == "delete")
        {
            if(q.dequeu() != -1)  
            {
                cout<< q.dequeu() << endl;
            }
        }
        else if(s == "back")
        {
            if(q.back() != -1) 
            {
                cout<< q.back() << endl;
            }
        }
        else if(s == "front")
        {
            cout<< q.Front() << endl;
        }
        else if(s == "size")
        {
            cout<< q.Size() << endl;
        }
        else if(s == "display")
        {
            q.display();
        }
    }
} 
