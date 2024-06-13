#include<iostream>
// #include<queue>

using namespace std;


// TC - O(1) SC - O(n)
class Queue {
    int* arr;
    int front;
    int rear;
    int size;

    Queue(int size) {
        this->front = this->rear = 0;
        this->size = size;
        arr = new int[size];
    }

    public:
        bool isEmpty();
        int onFront();
        void enqueue(int val);
        int dequeue();
};

bool Queue::isEmpty() {
    if(front == rear) {
        return true;
    }
    return false;
}

void Queue::enqueue(int data) {
    if(this->rear == size) {
        cout<<"Queue is full"<<endl;
    } else {
        arr[rear++] = data;
    }
}

int Queue::dequeue() {
    if(this->front == this->rear) {
        cout<<"Queue is Empty"<<endl;
        // this->front = this->rear = 0;
        return -1;
    } else {
        int val = arr[this->front];
        arr[front] = -1;
        if(front == rear) {
            front = rear = 0;
        }

        return val;
    }
}

int Queue::onFront() {
    if(front == rear) {
        return -1;
    }
    return arr[front];
}



int main() {
    return 0;
}