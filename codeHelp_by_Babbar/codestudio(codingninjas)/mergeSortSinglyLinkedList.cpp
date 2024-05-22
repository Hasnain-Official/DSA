#include<iostream>
#include<vector>
#include<algorithm>

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

/*
    Merge sort in Singly Linked List
*/

// find Middle Element in List - this approach is called Tortoise and Hare Approach
Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// merge List
Node* mergeList(Node* leftList, Node* rightList) {
    // in case left list or right list is null then return accordingly
    if(leftList == NULL) return rightList;
    if(rightList == NULL) return leftList;

    // create a answer list
    Node* ans = new Node(-1);

    // merge the sorted list 
    Node* temp = ans;
    while(leftList != NULL && rightList != NULL) {
        if(leftList < rightList) {
            temp->next = leftList;
            temp = leftList;
            leftList = leftList->next;
        } else {
            temp->next = rightList;
            temp = rightList;
            rightList = rightList->next;
        }
    }

    // in case left list contains node 
    while(leftList != NULL) {
        temp->next = leftList;
        temp = leftList;
        leftList = leftList->next;
    }

    // in case right list contains node 
    while(rightList != NULL) {
        temp->next = rightList;
        temp = rightList;
        rightList = rightList->next;
    }

    // OR

    // if(leftList != NULL) temp->next = leftList;
    // if(rightList != NULL) temp->next = rightList;

    // move the pointer to skip the dummy node
    ans = ans->next;
    return ans;
}



// recursive way approach for merge sort
Node* mergeSortSinglyLinkedList(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* mid = findMid(head);
    Node* left = mergeSortSinglyLinkedList(head);
    Node* right = mergeSortSinglyLinkedList(mid->next);
    mid->next = NULL;

    Node* res = mergeList(left, right);
    return res;
}

int main() {
    return 0;
}