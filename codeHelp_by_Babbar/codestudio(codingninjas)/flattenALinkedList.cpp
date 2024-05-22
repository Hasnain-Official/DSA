#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Node {
    public : 
        int data;
        Node* next;
        Node* child;
        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->child = NULL;
        }
};

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

    // OR Simply

    // if(leftList != NULL) temp->next = leftList;
    // if(rightList != NULL) temp->next = rightList;

    // move the pointer to skip the dummy node
    temp = ans;
    ans = ans->next;
    temp->next = NULL;
    delete temp;

    return ans;
}

// solve recusively 
/*
    solve() : go through each next pointer using recusrion
*/
Node* solve(Node* head) {
    if(head == NULL) return head;

    // returns the sorted list
    Node* sortedNext = solve(head->next);

    // merging the sorted list with child list
    Node* res = mergeList(head->child, sortedNext);

    // setting next pointer to null
    head->next = NULL;

    // returns the merged list
    return res;
}


/*
    Approach : 
    1. Create a list.
    2. Using recursion, next and child list merging with merge2sortedlist function(assuming solve function returns the sorted list).
    3. return the resultant list
*/
Node* flattenALinkedList(Node* head) {
    // base condition
    if(head == NULL || (head->next == NULL && head->child == NULL)) return head;

    // resultant list
    Node* ans = new Node(-1);
    Node* ansTail = ans;

    // in case only one node is available and next pointer is null.
    if(head->next == NULL) {
        Node* temp = head;
        while (temp != NULL) {
            Node* newNode = new Node(temp->data);
            ansTail->next = newNode;
            ansTail = newNode;
            temp = temp->child;
        }
        return ans;
    }

    // returns the flattened list in ans
    ans->next = solve(head);

    return ans->next;
}

int main() {
    return 0;
}

