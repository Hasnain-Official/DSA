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

// Approach - 1 : count no. of 0,1,2 and replace data of each node
Node* sortLinkedList0s1s2s(Node* head) {
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    Node* curr = head;

    // count no. of zeros, ones, twos
    while(curr != NULL) {
        if(curr->data == 0) {
            zeroCount++;
        } else if(curr->data == 1) {
            oneCount++;
        } else {
            twoCount++;
        }
        curr = curr->next;
    }

    // replace the node data
    curr = head;
    while(curr != NULL) {
        if(zeroCount > 0) {
            curr->data = 0;
            zeroCount--;
        } else if(oneCount > 0) {
            curr->data = 1;
            oneCount--;
        } else if(twoCount > 0){
            curr->data = 2;
            twoCount--;
        }
        curr = curr->next;
    }
   return head;
}

void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

// Approach - 2 : create list for each 0,1,2 (link update approach)
Node* sortList0s1s2s(Node* head) {
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneTail = oneHead;
    Node* twoTail = twoHead;
    Node* curr = head;

    while(curr != NULL) {
        if(curr->data == 0) {
            insertAtTail(zeroTail, curr);
        } else if(curr->data == 1) {
            insertAtTail(oneTail, curr);
        } else if(curr->data == 2) {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge 3 lists
    if(oneHead != NULL) {
        zeroTail->next = oneHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // head rebase
    head = oneHead->next;

    // delete the -1 nodes created above
    delete oneHead;
    delete zeroHead;
    delete twoHead;

    return head;
}

int main() {
    return 0;
}