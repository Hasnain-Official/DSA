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


// Method - 1, TC - O(n2) , SC - O(n)
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

bool checkForBalancedTree(Node* root) {
    if(root == NULL) {
        return true;
    }

    bool left = checkForBalancedTree(root->left);
    bool right = checkForBalancedTree(root->right);

    int leftHeight = heightOfABinaryTree(root->left);
    int rightHeight = heightOfABinaryTree(root->right);
    bool diff = abs(leftHeight - rightHeight + 1) <= 1;

    if(left && right && diff) {
        return true;
    }

    return false;
}









// Method - 2 , TC - O(n) , SC - O(n)

/**
 * Intuition : 
 * - we need height with the returned bool value is balanced or not.
 * - can use pair for the bool value and height of the tree.
 */

using P = pair<bool,int>;

P checkForBalancedTreeUsingPair(Node* root) {
    if(root == NULL) {
        P p = {true, 0};
        return p;
    } 

    P ans;
    P left = checkForBalancedTreeUsingPair(root->left);
    P right = checkForBalancedTreeUsingPair(root->right);
    bool diff = abs(left.second - right.second + 1) <= 1;
    ans.first = ((left.first && right.first) && diff);
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

bool checkForBalancedTree2(Node* root) {
    P ans;
    ans = checkForBalancedTreeUsingPair(root);

    return ans.first;
}





int main() {
    return 0;
}