#include<iostream>
#include<queue>

using namespace std;

class Node {
    public :
        int data;
        Node* left;
        Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
}

Node* buildTree(Node* root) {
    cout<<"Enter the data :"<<endl;
    int data;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    root = new Node(data);

    cout<<"Left child for "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Right child for "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void inOrderTraversal(Node* root) {

    if(root == NULL) {
        return ;
    }

    inOrderTraversal(root->left);
    cout<<"Data - > "<<data<<endl;
    inOrderTraversal(root->right);

}

void preOrderTraversal(Node* root) {

    if(root == NULL) {
        return ;
    }

    cout<<"Data - > "<<root->data<<endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}

void postOrderTraversal(Node* root) {

    if(root == NULL) {
        return ;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<"Data - > "<<root->data<<endl;

}

void levelOrderTraversal(Node* root) {
    if(root == NULL) {
        return ;
    }

    queue<Node*> q;

    q.push(root);
    cout<<"------Level Order Traversal ------"<<endl;
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout<<"DATA - > "<<temp->data<<endl;
        if(temp->left != NULL) {
            q.push(temp->left);
        }

        if(temp->right != NULL) {
            q.push(tmep->right);
        }
    }
}

int main() {

    Node* root = NULL;

    root = buildTree(root);

    return 0;
}