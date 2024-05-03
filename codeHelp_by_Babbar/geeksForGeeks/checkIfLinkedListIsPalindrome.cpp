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

bool isListPalindrome(Node* &head) {
    if(head == NULL) {
        return false;
    }
    vector<int> v;
    Node* temp = head;
    while(temp != NULL) {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int s = 0, e = v.size() - 1;

    while(s <= e) {
        if(s != e) return false;
        s++;
        e--;
    }
    return true;
}

// approach 2 - get the mid element and rev the half list and then compare, space complexity - O(1), TC - O(n)
Node* getMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

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

bool isListPalindrome2(Node* head) {
    if(head == NULL) {
        return false;
    }
    if(head->next == NULL) {
        return true;
    }

    Node* mid = getMid(head);
    Node* temp = mid->next;
    mid->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = mid->next;
    while(head1 != NULL && head2 != NULL) {
        if(head1->data != head2->data) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    if(head1 != NULL || head2 != NULL) {
        return false;
    }
    return true;
}


int main() {

    // bool res = isListPalindrome();
    // if(res) {
    //     cout<<"List is Palindrome"<<endl;
    // } else {
    //     cout<<"List is not a Palindrome"<<endl;
    // }
    return 0;
}