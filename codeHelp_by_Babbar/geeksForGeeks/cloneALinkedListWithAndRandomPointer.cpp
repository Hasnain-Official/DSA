#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Node class to create a new Node
class Node {
    public : 
        int data;
        Node* next;

        // on platform random is given arb;
        Node* random;
        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }
        Node(int data, Node* random) {
            this->data = data;
            this->next = NULL;
            this->random = random;
        }
};

void insertAtTail(Node* tail, int newData) {
    tail->next = new Node(newData);
    tail = tail->next;
}


// use map to store the mapping of the original to clone list
Node* cloneALinkedListWithAndRandomPointerMapApproach(Node* head) {

    // return cloned list in case of null or next value is null
    Node* cloneHead = NULL;
    if(head == NULL) {
        return cloneHead;
    }  
    if(head->next == NULL) {
        cloneHead = new Node(head->data, head->random);
        return cloneHead;
    }
    cloneHead = new Node(-1);
    Node* cloneTail = cloneHead;

    // create map for the reference of the cloned list, Space complexity becomes O(n)
    map<Node*, Node*> m;

    // copy the list to new one
    Node* temp = head->next;
    while (temp != NULL) {
        insertAtTail(cloneTail, temp->data);
        temp = temp->next;
    }

    // set the mapping of the random pointers
    temp = head;
    Node* cloneTemp = cloneHead->next;
    while(temp != NULL) {
        m[temp] = cloneTemp;
        cloneTemp = cloneTemp->next;
        temp = temp->next;
    }

    // set the random pointer of cloned list using map
    cloneTemp = cloneHead->next;
    temp = head;
    while(cloneTemp != NULL && temp != NULL) {

        // setting the value of random pointer to cloned list random pointers
        cloneTemp->next = m[temp->random];

        // move the pointer to next node as the value of random pointers assigned
        cloneTemp = cloneTemp->next;
        temp = temp->next;
    }

    // skip or delete the first node of cloned list coz above a dummy node is created at start
    temp = cloneHead;
    cloneHead = cloneHead->next;
    temp->next = NULL;
    delete temp;

    return cloneHead;
    // return cloneHead->next;
}

// video answer
/*
    Approach - 3 
    1. copy the original list
    2. add the cloned nodes in between the original node one by one
    3. resultant list will be contained the cloned nodes in between.(imagine it zigzag for better understanding and explanation)
    4. copy the random pointer to cloned nodes.
    5. revert the cloned nodes insertion in point no. 2 and 3.
    6. return the cloned list head.
*/
void insertAtTail(Node* &head, Node* &tail, int newData) {
    Node* temp = new Node(newData);
    if(head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = tail->next;
    }
}
Node* cloneALinkedListWithAndRandomPointerConstantComplexity(Node* head) {

    // Create an empty clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    // new pointer to point the original list
    Node* temp = head;

    // copy original list to cloned list
    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // clone nodes to be added in between the original nodes
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL) {
        // create a pointer so that the original list won't get lost
        Node* nextNode = originalNode->next;

        // point original node next pointer to cloned node
        originalNode->next = cloneNode;

        // set the original node pointer to nextNode which points original list
        originalNode = nextNode;

        // change pointer to clone list so that clone list won't get lost
        nextNode = cloneNode->next;

        // cloned node pointer's next to original node, and insertion has been completed here
        cloneNode->next = originalNode;

        // move the clone node pointer to next node for next iteration.
        cloneNode = nextNode;
    }

    // set random pointer in nodes, also called arb in question on platform
    temp = head;
    // traverse the list 
    while(temp != NULL) {

        // check condition whether next node is null while moving further.
        if(temp->next != NULL) {
            /* 
            (imagine in the list : now the pointer pointing node is the original list node and it's next node is cloned list node) 
            so the temp->next->random will be the cloned node.
            might be scenario random is null, in case of null the temp->random will be set
            in case of existing random node it will set the value.
            */
            temp->next->random = temp->random ? temp->random->next : temp->random;
        }
        // move pointer to it's next node.
        temp = temp->next->next;
    }

    // revert the above zig zag list for resultant list.
    originalNode = head;
    cloneNode = cloneHead;
    while(originalNode != NULL && cloneNode != NULL) {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
        if(originalNode != NULL) cloneNode->next = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

int main() {
    return 0;
}