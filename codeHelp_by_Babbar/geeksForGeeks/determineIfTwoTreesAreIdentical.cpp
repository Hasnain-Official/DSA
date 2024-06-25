#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Time Complexity - O(n), SC - O(n)
bool determineIfTwoTreesAreIdentical(Node* r1, Node* r2) {

    // base condition - if r1 and r2 becomes NULL
    if((r1 == NULL && r2 == NULL)) {
        return true;
    }

    // either of one is false results false
    if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)) {
        return false;
    }
    
    // compare the left
    bool left = determineIfTwoTreesAreIdentical(r1->left, r2->left);
    // compare the right
    bool right = determineIfTwoTreesAreIdentical(r1->right, r2->right);

    // left is true, right is true, and data should be equal
    return (left && right && (r1->data == r2->data));
}

int main() {
    return 0;
}