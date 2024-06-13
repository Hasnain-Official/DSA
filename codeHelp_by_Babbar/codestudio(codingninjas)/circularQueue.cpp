#include<iostream>

using namespace std;

class circularQueue {
    public:
        int* arr;
        int size;
        int front;
        int rear;
    circularQueue(int size) {
        this->front = this->rear = -1;
        this->size = size;
        arr = new int[size];
    }
    bool enqueue(int n);
    int dequeue();
};

bool circularQueue::enqueue(int n) {
    if((front == 0 && rear == size - 1) || (rear == (front-1)%(size-1))) {
        // cout<<"Queue is full."<<endl;
        return false;
    } else if(front == -1) { // pushing first element
        front = rear = 0;
        arr[rear] = n;
    } else if(rear == size-1 && front != 0) {
        arr[rear] = n;
        rear = 0;
    } else {
        arr[rear] = n;
        rear++;
    }
    return true;
}

int circularQueue::dequeue() {
    if(front == rear == -1) {
        return -1;
    }
    int ans = arr[front];
    arr[front] = -1;
    if(front == rear) {
        front = rear = -1;
    }
    else if(front == size-1) {
        front = 0;
    } else {
        front++;
    }
    return ans;
}

int main() {
    return 0;
}