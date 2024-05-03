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

void solve(Node* &head, Node* curr, Node* prev) {
    // base condition
    if(curr == NULL) {
        head = prev;
        return;
    }

    // make the pointer to point the prev node at each recursive call , in case of doubly linked list(curr->prev = curr->next)
    solve(head, curr->next, curr);
    curr->next = prev;
}

Node* reverseLLRecursion(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    solve(head, curr, prev);
    return prev;
}


// Time Complexity - O(n), Space Complexity - O(1)
Node* reverseLL(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forw = NULL;
    while (curr != NULL) {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

int main() {
    
    return 0;
}