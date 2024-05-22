#include<iostream>
#include<vector>

using namespace std;

class Node {
    public : 
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            this->next = NULL;
        }
};


// TC - O(n) and SC - O(1)
// using recursion
Node* removeNodes(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* nextNode = removeNodes(head->next);
    if(head->val < nextNode->val ) {
        delete head;
        return nextNode;
    }
    head->next = nextNode;
    return head;
}



int main() {
    return 0;
}