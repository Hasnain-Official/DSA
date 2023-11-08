#include<iostream>

using namespace std;

struct  Node {
    Node *left;
    int data;
    int height;
    Node *right;
} *root = NULL;

int NodeHeight(Node *p) {
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    return (hl > hr) ? hl + 1 : hr + 1;
}

int balance_factor(Node *p) {
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    return hl - hr;
}

Node* LLRotation(Node* p) {
    Node* pl = p->left;
    Node* plr = pl->right;

    pl->right = p;
    p->left = pl->right;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p) {
        root = pl;
    }
    return pl;
}

Node* RRRotation(Node* p) {
    Node *pr = p->right;
    Node* prl = pr->left;

    pr->left = p;
    p->right = pr->left;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    if(root == p) {
        root = pr;
    }
    return pr;
}
Node* LRRotation(Node* p) {
    Node* pl = p->left;
    Node* pr = p->right;
    Node* plr = pl->right;

    pl->right = plr->left;
    p->right = plr->right;
    plr->left = pl;
    plr->right = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(root == p) {
        root = plr;
    }
    return plr;
}
Node* RLRotation(Node* p) {
    Node* pr = p->right;
    Node* pl = p->left;
    Node* prl = pr->left;

    p->right = prl->left;
    pr->left = prl->right;
    prl->left = p;
    prl->right = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if(root == p) {
        root = prl;
    }
    return prl;
}

Node* RInsert(Node *p, int key) {
    if(p == NULL) {
        Node *t = new Node();
        t->data = key;
        t->height = 1;
        t->left = t->right = NULL;
        return t;
    }
     if(key < p->data) {
        RInsert(p->left, key);
     } else if(key > p->data) {
        RInsert(p->right, key);
     }
    p->height = NodeHeight(p);
    if(balance_factor(p) == 2 && balance_factor(p->left) == 1) {
        return LLRotation(p);
    } else if(balance_factor(p) == 2 && balance_factor(p->left) == -1) {
        return LRRotation(p);
    } else if(balance_factor(p) == -2 && balance_factor(p->right) == -1) {
        return RLRotation(p);
    } else if(balance_factor(p) == -2 && balance_factor(p->right) == 1) {
        return RRRotation(p);
    }
    return p;
}


int main() {

    root = RInsert(root, 50);
    RInsert(root, 10);
    RInsert(root, 20);

    return 0;
}