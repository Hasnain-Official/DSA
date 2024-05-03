#include<iostream>
#include<vector>
#include<unordered_map>

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

Node* removeDuplicatesFromUnsortedList(Node* head) {
    if(head == NULL) return head;
    unordered_map<Node*, bool> map;
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL) {
        if(map[curr]) {
            Node* nodeToDelete = curr;
            delete(nodeToDelete);
            curr = prev;
        } else {
            map[curr] = true;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

int main() {
    return 0;
}