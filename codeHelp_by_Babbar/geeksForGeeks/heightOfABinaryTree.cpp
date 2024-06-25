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

// Time Complexity - O(n)
// Space Complexity - O(n)

int heightOfABinaryTree(Node* node) {
    if(node  == NULL) {
        return 0;
    }
    // height of left subtree
    int leftHeight = heightOfABinaryTree(node->left);
    // height of right sb tree
    int rightHeight = heightOfABinaryTree(node->right);

    // max height along with the parent node
    return (max(leftHeight, rightHeight) + 1);

}

int main() {
    return 0;
}