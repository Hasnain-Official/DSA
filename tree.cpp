#include<iostream>
#include<queue>
using namespace std;


struct Node {
    Node* left;
    int data;
    Node* right;
};

class Tree {
    public : 
        Node* root;
        queue<Node*> q;
        Tree() {root == NULL;};
        void create();
        void pre_order(Node* p);
        void in_order(Node* p);
        void post_order(Node* p);
        void level_order(Node* root);
        int height(Node* root);
};

void Tree::create() {
    Node *p, *t;
    int x;
    cout<<"Enter the Root Element"<<endl;
    cin>>x;
    root = new Node();
    root->data = x;
    root->left = root->right = 0;
    p = root;
    q.push(root);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        cout<<"Enter the Left Child - > "<<endl;
        cin>>x;
        if(x != -1) {
            t = new Node();
            t->data = x;
            t->left = t->right = 0;
            p->left = t;
            q.push(t);
        }

        cout<<"Enter the Right Child - > "<<endl;
        cin>>x;
        if(x != -1) {
            t = new Node();
            t->data = x;
            t->left = t->right = 0;
            p->right = t;
            q.push(t);
        }
    }
}

void Tree::pre_order(Node *p) {
    if(p) {
        cout<<" - > "<<p->data<<endl;
        pre_order(p->left);
        pre_order(p->right);
    }
}

void Tree::in_order(Node *p) {
    if(p) {
        in_order(p->left);
        cout<<" - > "<<p->data<<endl;
        in_order(p->right);
    }
}

void Tree::post_order(Node *p) {
    if(p) {
        post_order(p->left);
        post_order(p->right);
        cout<<" - > "<<p->data<<endl;
    }
}

void Tree::level_order(Node *root) {
    cout<<"Level Order"<<endl;
    Node *p = root;
    cout<<" - > "<<p->data<<endl;
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if(p->left) {
            cout<<" - > "<<p->left->data<<endl;
            q.push(p->left);
        }
        if(p->right) {
            cout<<" - > "<<p->right->data<<endl;
            q.push(p->right);
        }
    }
    
}

int Tree::height(Node* root) {
    int x = 0, y = 0;
    if(root == 0) {
        return 0;
    }
    x = height(root->left);
    y = height(root->right);
    if(x > y) {
        return x + 1;
    } else {
        return y + 1;
    }
}

int main() {
    Tree t;
    t.create();

    cout<<"Pre Order : "<<endl;
    t.pre_order(t.root);
    cout<<"In Order : "<<endl;
    t.in_order(t.root);
    cout<<"Post Order : "<<endl;
    t.post_order(t.root);
    cout<<"Level Order : "<<endl;
    t.level_order(t.root);
    cout<<"Height : "<<t.height(t.root)<<endl;
    return 0;
}