#include<iostream>
#include<queue>

using namespace std;

// struct Queue {
//     int size;
//     int front;
//     int rear;
//     int *Q;
// } *q;

// void createQueue(int size){
//     q = new Queue;
//     q->size = size - 1;
//     q->front = -1;
//     q->rear = -1;
//     q->Q = new int[size];
// }




struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
} q;

void createQueue(int size){
    q.size = size - 1;
    q.front = -1;
    q.rear = -1;
    q.Q = new int[size - 1];
}

bool is_empty() {
    if(q.front == q.rear) {
        return true;
    }
    return false;
}

// Complexity - O(1)
void enqueue(int x) {
    if(q.rear == q.size){
        cout<<"Queue is Full"<<endl;
    } else {
        cout<<"x -> "<<x<<endl;
        q.rear = q.rear + 1;
        q.Q[q.rear] = x;
    }
}

// Complexity - O(1)
int dequeue() {
    int x = -1;
    if(q.front == q.rear) {
        cout<<"Queue is Empty"<<endl;
        q.front = -1;
        q.rear = -1;
    } else {
        q.front = q.front + 1;
        x = q.Q[q.front];
    }
    return x;
}



void Display() {
    for(int i = q.front + 1; i <= q.rear; i++) {
        cout<<" - > "<<q.Q[i]<<endl;
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
    cout<<"Dequeuing - > "<<dequeue()<<endl;
    cout<<"Dequeuing - > "<<dequeue()<<endl;
    cout<<"Dequeuing - > "<<dequeue()<<endl;
    cout<<"Dequeuing - > "<<dequeue()<<endl;
    cout<<"Dequeuing - > "<<dequeue()<<endl;
    Display();
    cout<<"Queue Size - > "<<q.size + 1<<endl;
    return 0;
}