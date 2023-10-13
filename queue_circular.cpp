#include<iostream>
#include<queue>

using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
} q;

void createQueue(int size){
    q.size = size;
    q.front = 0;
    q.rear = 0;
    q.Q = new int[size];
}

void enqueue(int x) {
    if((q.rear + 1)%q.size == q.front) {
        cout<<"Queue is Full"<<endl;
    } else {
        q.rear = (q.rear + 1) % q.size;
        q.Q[q.rear] = x;
    }
}


int dequeue() {
    int x = -1;
    if((q.front) == (q.rear)) {
        cout<<"Cannot dequeue, queue is Empty "<<endl;
    } else{
        q.front = q.front + 1;
        x = q.Q[q.front];
    }
    return x;
}


void Display() {
    if(q.front == q.rear) {
        cout<<"Queue is Empty"<<endl;
    } else {
        int i = q.front + 1;
        do {
            cout<<" - > "<<q.Q[i]<<endl;
            i = (i+1) % q.size;
        } while(i != (q.rear + 1) % q.size);
    }
}

int main() {
     int size = 0;
    cout<<"Enter the size of Queue : "<<endl;
    cin>>size;
    createQueue(size);
    enqueue(5);
    enqueue(1);
    enqueue(3);
    enqueue(2);
    enqueue(6);
    enqueue(4);
    Display();
    cout<<"-------------After dequeue---------"<<endl;
    cout<<" Dequeued - > "<<dequeue()<<endl;
    cout<<" Dequeued - > "<<dequeue()<<endl;
    cout<<" Dequeued - > "<<dequeue()<<endl;
    cout<<" Dequeued - > "<<dequeue()<<endl;
    cout<<" Dequeued - > "<<dequeue()<<endl;
    Display();
    cout<<"Queue Size - > "<<q.size - 1 <<endl;
    return 0;
}