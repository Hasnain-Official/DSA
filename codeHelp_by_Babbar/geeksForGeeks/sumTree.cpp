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

// int solve(Node* root) {
//     if(root == NULL) {
//         return 0;
//     }

//     int left = solve(root->left);
//     int right = solve(root->right);

//     return left + right;
// }


/**
 * Intuition :
 * - Use pair for storing the isSUmTree bool value and sum for each node except leaf node
 */
using P = pair<bool, int>;

P solve(Node* root) {

    // base condition - root is NULL
    if(root == NULL) {
        P p = {true, 0};
        return p;
    }
    // both the left and right is NULL
    if(root->left == NULL && root->right == NULL) {
         P p = {true, root->data};
        return p;
    }
    // return the pair ans;
    P ans;
    // left Sum Tree result stored in pair
    P leftSumTree = solve(root->left);
    // right sum tree result sotred in pair
    P rightSumTree = solve(root->right);

    // assign the condtion based first value of pair(ans)
    ans.first = ((leftSumTree.first && rightSumTree.first) && ((leftSumTree.second + rightSumTree.second) == root->data)) ? true : false;
    // assign the sum of the left sum tree and right sum tree, include root->data as roots parent need the sum of whole left and whole right. 
    ans.second = root->data + leftSumTree.second + rightSumTree.second;

    return ans;
}

int sumTree(Node* root) {
    P sum;

    sum = solve(root);

    return sum.first;
}

int main() {
    std::cout << "Sum of tree: " << 0 << std::endl; // Output should be 6
    return 0;
}