#include<iostream>
#include<vector>

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

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = curr->next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtTail(Node* head, Node* tail, int digit) {
    Node* temp = new Node(digit);
    if(head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    return ;
}

Node* addList(Node* first, Node* second) {
    Node* ansHead = NULL;
    int carry = 0;
    Node* ansTail = NULL;
    while (first != NULL && second != NULL) {
        int sum = (first->data + second->data + carry)%10;
        insertAtTail(ansHead, ansTail, sum);
        carry = (first->data + second->data + carry)/10;
        first = first->next;
        second = second->next;
    }
    
    // in case first list still have node
    while (first != NULL)  {
         int sum = (first->data + carry)%10;
        insertAtTail(ansHead, ansTail, sum);
        carry = (first->data + carry)/10;
        first = first->next;
    }

    // in case second list still have node
    while (second != NULL)  {
         int sum = (second->data + carry)%10;
        insertAtTail(ansHead, ansTail, sum);
        carry = (second->data + carry)/10;
        second = second->next;
    }

    while (carry != 0)  {
        int sum = carry;
        insertAtTail(ansHead, ansTail, sum);
        carry = sum/10;
    }

    // return the output list
    return ansHead;
}


// optimized approach
Node* addList2(Node* first, Node* second) {
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    while (first != NULL || second != NULL || carry != 0) {
        int val1 = 0, val2 = 0;
        if(first->data != NULL) val1 = first->data;
        if(second->data != NULL) val2 = second->data;

        int sum = (val1 + val2 + carry)%10;
        insertAtTail(ansHead, ansTail, sum);
        carry = (val1 + val2 + carry)/10;
        if(first != NULL) first = first->next;
        if(second != NULL) second = second->next;
    }
    
    // return the output list
    return ansHead;
}

Node* add2NumbersOfLinkedList(Node* first, Node* second) {
    // reverse both lists
    first = reverse(first);
    second = reverse(second);

    // add 2 list
    Node* ans = addList(first, second);

    // reverse the resultant list
    ans = reverse(ans);

    // return the resultant list
    return ans;
}

int main(){
    return 0;
}