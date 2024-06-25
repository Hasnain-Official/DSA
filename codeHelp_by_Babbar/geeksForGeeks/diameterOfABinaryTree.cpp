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

// Method : 1, TC - O(n2) and SC - O(n)

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

// In this approach as diameter is taking O(n) and height also takes O(n) becomes O(n2)
int diameterOfABinaryTree(Node* root) {
    int ans = 0;

    int op1 = diameterOfABinaryTree(root->left);
    int op2 = diameterOfABinaryTree(root->right);
    int op3 = heightOfABinaryTree(root->left) + heightOfABinaryTree(root->right) + 1;

    ans = max(op1, max(op2, op3));

    return ans;
}


// Method - 2, TC - O(n) , SC - O(n)
using P = pair<int,int>;

P diameterWithHeight(Node* node) {
    // base case
    if(node == NULL) {
        P p = {0,0};
        return p;
    }
    // diameter with height of left
    P left = diameterWithHeight(node->left);

    // diameter with height of right
    P right = diameterWithHeight(node->right);

    // diameter of left part
    int op1 = left.first;

    // diameter of right part
    int op2 = right.first;

    // height of left + right + 1
    int op3 = left.second + right.second + 1;

    P ans;
    // set the maximum diameter
    ans.first = max(op1, max(op2, op3));
    // set the height of tree
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

// TC - O(n), SC - O(n)
int diameterOfABinaryTree(Node* root) {
    P ans;

    ans = diameterWithHeight(root);

    return ans.first;
}



int main() {
    return 0;
}