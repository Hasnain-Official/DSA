#include<iostream>

using namespace std;

class Node {
    public : 
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

// unique data
// is Circularly Linked List
bool isCircularlyLinked(Node* head) {
    if(head == NULL) {
        return true;
    }
    if(head->next == NULL) {
        return false;
    }
    Node* temp = head->next;
    while(temp != NULL && temp != head) {
        temp = temp->next;
    }
    if(temp == head) {
        return true;
    }
    return false;
}

int main() {
    return 0;
}