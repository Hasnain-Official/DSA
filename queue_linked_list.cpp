#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* t = new Node();
    if(t == NULL) {
        cout<<"Queue is Full"<<endl;
    } else {
        t->data = x;
        t->next = NULL;
        if(front == NULL) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = rear->next;
        }
    }
}

int dequeue() {
    int x = -1;
    if(front == NULL) {
        cout<<"Queue is Empty"<<endl;  
    } else {
        Node* p;
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display() {
    if(front == NULL) {
        cout<<"Cannot Display, Queue is Empty"<<endl;
    } else {
        Node* p = front;
        while (p != rear->next) {
            cout<<" - > "<<p->data<<endl;
            p = p->next;
        }
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    cout<<"-------------After Dequeuing---------------"<<endl;
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}