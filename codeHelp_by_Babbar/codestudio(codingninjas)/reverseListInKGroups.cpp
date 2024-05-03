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

// Time Complexity - O(n), Space Complexity - O(n)
Node* reverseListInKGroup(Node* head, int k) {
    if(head == NULL) {
        return head;
    }

    // reverse fist k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    // step 1
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 2
    while (next != NULL) {
        head->next = reverseListInKGroup(next, k);
    }
    
    return prev;
}

int main() {
    return 0;
}