#include<iostream>

using namespace std;

// Method : Element Priority

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
};


/*
Considering way 
Insert in same order and delete max priority by searching it.
*/ 
// Conplexity - O(1)
// void enqueue(int x) {
//     if(q.rear == q.size){
//         cout<<"Queue is Full"<<endl;
//     } else {
//         cout<<"x -> "<<x<<endl;
//         q.rear = q.rear + 1;
//         q.Q[q.rear] = x;
//     }
// }

// Complexity - O(n)
// int dequeue() {
//     int x = -1;
//     int index_x = -1;
//     if(q.front == q.rear) {
//         cout<<"Queue is Empty"<<endl;
//     } else {
//         for (int i = q.front+1; i <= q.rear; i++) {
//             if(q.Q[i] > x ) {
//                 x = q.Q[i];
//                 index_x = i;
//             }
//         }
//         for (int i = index_x; i < q.rear; i++) {
//             q.Q[i] = q.Q[i+1];
//         }
//         q.rear = q.rear - 1;
//     }
//     return x;
// }


/*
Considering way
Insert by priority and delete in same order
Max - 1
Min - 10
*/
// Complexity - O(n)
void enqueue(int x) {
    if(q.rear == q.size) {
        cout<<"Queue is Full"<<endl;
    } else {
        if(q.rear == -1) {
            q.rear = q.rear + 1;
            q.Q[q.rear] = x;
        } else {
            int i = q.rear;
            while (x < q.Q[i]) {
                q.Q[i+1] = q.Q[i];
                i--;
            }
            q.Q[i+1] = x;
            q.rear = q.rear + 1;
        }
    }
}

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


// Complexity - O(n)
void display() {
    if(q.front == q.rear) {
        cout<<"Cannot Display, Queue is Empty"<<endl;
    } else {
        for(int i = q.front + 1; i <= q.rear; i++) {
           cout<<"Element - > "<<q.Q[i]<<endl;
        }
    }    
}


int main() {
    createQueue(5);
    enqueue(5);
    enqueue(4);
    enqueue(4);
    enqueue(6);
    display();
    cout<<"-------------After Dequeuing----------"<<endl;
    dequeue();
    dequeue();
    display();
    return 0;
}