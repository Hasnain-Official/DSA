#include<iostream>

using namespace std;

// In java, 10 is highest priority and 1 is lowest priority


// Method :  Limited Set of Priorities



// Method 1
struct Queue {
    int front;
    int rear;
    int size;
    char* Q;
} q1, q2, q3;

void create_q1(int size) {
    q1.size = size - 1;
    q1.front = -1;
    q1.rear = -1;
    q1.Q = new char[size - 1];
}

void create_q2(int size) {
    q2.size = size - 1;
    q2.front = -1;
    q2.rear = -1;
    q2.Q = new char[size - 1];
}

void create_q3(int size) {
    q3.size = size - 1;
    q3.front = -1;
    q3.rear = -1;
    q3.Q = new char[size - 1];
}

void insert_queue(Queue &q, char x) {
     if(q.rear == q.size){
        cout<<"Queue is Full"<<endl;
    } else {
        cout<<"x -> "<<x<<endl;
        q.rear = q.rear + 1;
        q.Q[q.rear] = x;
    }
}
bool is_queue_empty(Queue &q) {
    if(q.front == q.rear) {
        return true;
    }
    return false;
}

void enqueue(char element, int priority) {
    if(priority > 3) {
        cout<<"Priority cannot be greater than s" + priority<<endl;
    } else {
        switch (priority) {
        case 1:
            insert_queue(q1, element);
            break;
        
        case 2:
            insert_queue(q2, element);
            break;

        case 3:
            insert_queue(q3, element);
            break;
        
        default:
            break;
        }
    }
}

int dequeue(){
    char x = '\0';

    if(is_queue_empty(q1)) {
        cout<<"Queue 1 is Empty"<<endl;
        q1.front = q1.rear = -1;
    }
    if(is_queue_empty(q2)) {
        cout<<"Queue 2 is Empty"<<endl;
        q2.front = q2.rear = -1;
    }
    if(is_queue_empty(q3)) {
        cout<<"Queue 3 is Empty"<<endl;
        q3.front = q3.rear = -1;
    }

    if(!is_queue_empty(q1)) {
        q1.front = q1.front + 1;
        x = q1.Q[q1.front];
    } else if(!is_queue_empty(q2)) {
        q2.front = q2.front + 1;
        x = q2.Q[q2.front];
    } else if(!is_queue_empty(q3)) {
        q3.front = q3.front + 1;
        x = q3.Q[q3.front];
    }
    return x;
}

void display(Queue &q) {
    if(q.front == q.rear) {
        cout<<"Cannot Display, Queue is Empty"<<endl;
    } else {
        for(int i = q.front + 1; i <= q.rear; i++) {
            cout<<" - > "<<q.Q[i]<<endl;
        }
    }
}

void all_display() {
    display(q1);
    display(q2);
    display(q3);
}


int main() {
    create_q1(5);
    create_q2(5);
    create_q3(5);
    enqueue('A', 1);
    all_display();
    dequeue();
    all_display();
    return 0;
}