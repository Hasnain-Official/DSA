#include<iostream>

using namespace std;

struct Stack {
    int top;
    int size;
    int* s;
} s1, s2;

void create_stack(Stack &st) {
    cout<<"Enter the size of the Stack : "<<endl;
    cin>>st.size;
    st.top = -1;
    st.s = new int[st.size];
}

void push(Stack &st, int x) {
    if(st.top == st.size - 1) {
        cout<<"Stack Overflow"<<endl;
    } else {
        st.s[++st.top] = x;
    }
}

int pop(Stack &st) {
    int x = -1;
    if(st.top == -1) {
        cout<<"Stack Underflow"<<endl;
    } else {
        x = st.s[st.top--];
    }
    return x;
}

bool is_stack_empty(Stack &st) {
    if(st.top == -1) {
        return true;
    }
    return false;
}


void enqueue(int x) {
    cout<<"Enqueuing - > "<<x<<endl;
    push(s1, x);
}

int dequeue() {
    int x = -1;
    if(is_stack_empty(s2)) {
        if(is_stack_empty(s1)) {
            cout<<"Queue is Empty"<<endl;
        } else {
            while (!is_stack_empty(s1)) {
                x = pop(s1);
                push(s2, x);
                // push(s2, pop(s1));
            }
        }
    } else {
        x = pop(s2);
    }
    cout<<"Dequeuing - > "<<x<<endl;
    return x;
}

int main() {     
    create_stack(s1);
    create_stack(s2);
    enqueue(5);
    enqueue(4);
    enqueue(4);
    enqueue(6);
    cout<<"-------------After Dequeuing----------"<<endl;
    dequeue();
    dequeue();
    return 0;
}