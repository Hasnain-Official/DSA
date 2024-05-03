#include<iostream>
#include<map>

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

bool detectCycle(Node* head) {
    if(head == NULL) {
        return false;
    }
    Node* temp = head;
    map<Node*, bool> visited;
    while (temp != NULL) {
        if(visited[temp]) {
            return true;
        } else {
            visited[temp] = true;
        }
        temp = temp->next;
    }
    return false;
}

Node* floydCycleDetection(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;

    while(slow != NULL && fast != NULL && slow != fast && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"Cycle is present at -> "<<slow->data<<endl;
    // return slow == fast;
    return slow == fast ? slow : NULL;
}

Node* getStartingNodeOfLoop(Node* head) {
    Node* intersectingPoint = floydCycleDetection(head);
    Node* slow = head;
    if(intersectingPoint != NULL) {
        while(slow != intersectingPoint) {
            slow = slow->next;
            intersectingPoint = intersectingPoint->next;
        }
        return slow;
    } else {
        return NULL;
    }
}

Node* removeCycle(Node* head) {
    if(head == NULL) {
        return head;
    }
    Node* intersectingPoint = floydCycleDetection(head);
    Node* startingNodeOfLoop = getStartingNodeOfLoop(head);
    if(startingNodeOfLoop == NULL) {
        return head;
    }
    Node* prev = NULL;
    while(intersectingPoint != startingNodeOfLoop) {
        prev = intersectingPoint;
        intersectingPoint = intersectingPoint->next;
        // startingNodeOfLoop = startingNodeOfLoop->next;      // isko ni bdhna hai
    }
    prev->next = NULL;
    return head;
}

int main() {
    return 0;
}