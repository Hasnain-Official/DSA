#include<iostream>

using namespace std;

struct Node {
    Node *left;
    int data;
    Node *right;
} *root = NULL;

struct Stack {
    int size;
    int top;
    Node **s;
} st;

void create_stack(Stack *st) {
    cout<<"Enter the Size of Stack - "<<endl;
    cin>>st->size;
    st->top = -1;
    st->s = new Node*[st->size];
};


void push(Stack *st, Node *x) {
    if(st->top == st->size - 1) {
        cout<<"Stack Overflow"<<endl;
    } else {
        st->s[++st->top] = x;
    }
}

Node* pop(Stack *st) {
    Node* x = NULL;
    if(st->top == -1) {
        cout<<"Stack Underflow"<<endl;
    } else {
        x = st->s[st->top--];
    }
    return x;
}


// Create Binary Search Tree
// Insertion in Binary Search Tree
// Method 1 - Iterative Approach
void iterative_insertion(Node *&p, int key) {
    Node *r, *t;
    Node* x = new Node();
    x->data = key;
    if(p == NULL) {
        p = x;
    } else {
        t = p; 
        while (t!=NULL) {
            r = t;
            if(key < t->data) {
                t = t->left;
            } else {
                t = t->right;
            }
        }
        if(key < r->data) {
            r->left = x;
        } else {
            r->right = x;
        }
    }
}

 
// Mehtod 2 - Recursive Approach
Node* recursive_insertion(Node *&p, int key) {
    Node* t;
    if(p == NULL) {
        t = new Node();
        t->data = key;
        t->left = t->right = NULL;
        p = t;
    } 
    if(key == p->data) {
        return p;
    }
    if(key < p->data) {
        p->left = recursive_insertion(p->left, key);
    } else if(key > p->data) {
        p->right = recursive_insertion(p->right, key);
    }
    return t;
}

int height(Node *p) {
    int x = 0, y = 0;
    if( p == 0) {
        return 0;;
    }
    x = height(p->left);
    y = height(p->right);
    return x > y ? x+y+1 : x+y;
}

Node* inpre(Node *p) {
    while (p && p->right != NULL) {
        p = p->right;
    }
    return p;
};

Node* insucc(Node *p) {
    while (p && p->left != NULL) {
        p = p->left;
    }
    return p;
};

// Deletion in Binary Search Tree
Node* recursive_delete(Node *&p, int key) {
    Node *q;
    if(p == NULL) {
        return NULL;
    }   
    if(p->left == NULL && p->right == NULL) {
        if(p == root) {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if(key < p->data) {
        p->left = recursive_delete(p->left, key);
    } else if(key > p->data) {
        p->right = recursive_delete(p->right, key);
    } else {
        if(height(p->left) > height(p->right)) {
            q = inpre(p->left);
            p->data = q ? q->data : p->data;
            p->left = recursive_delete(p->left, q->data);
        } else {
            q = insucc(p->right);
            p->data = q ? q->data : p->data;
            p->right = recursive_delete(p->right, q->data);
        }
    }
    return p;
}


// Searching in Binary Search Tree
// Method 1 - Recursive approach
int recursive_search(Node *t, int key) {
    if(t == NULL) {
        cout<<" Key not found"<<endl;
        return -1;
    }
    if(key == t->data) {
        return t->data;
    }
    if(key < t->data) {
        return recursive_search(t->left, key);
    } else if(key > t->data) {
        return recursive_search(t->right, key);
     }
    return t->data;
}

// Method 2 - Iterative Approach
int iterative_search(Node *p, int key) {
    int x = -1;
    if(p->data == key) {
        x = p->data;
    } else {
        Node* t = p;
        while (t != NULL) {
            if(key == t->data) {
                x = t->data;
            }
            if(key < t->data) {
                t = t->left;
            } else {
                t = t-> right;
            }
        }
    }
    return x;
}

void in_order(Node *p) {
    if(p) {
        in_order(p->left);
        cout<<" - > "<<p->data<<endl;
        in_order(p->right);
    }
}


bool is_stack_empty(Stack st) {
    if(st.top == -1) {
        return true;
    }
    return false;
}

// Generate BInary Search Tree from Preorder Array
void generate_preorder(int arr[], int n) {
    Node *t, *p;
    int i = 0;
    if(root == NULL) {
        root = new Node();
        root->data = arr[i++];
        root->left = root->right = NULL;
        p = root;
    }
    while (i < n) {
        if(arr[i] < p->data) {
            t = new Node();
            t->data = arr[i];
            t->left = t->right = NULL;
            p->left = t;
            push(&st, t);
            p = t;
        } else if((p->data > arr[i] && p->data < st.s[st.top]->data) || (p->data > arr[i] && is_stack_empty(st))) {
            t = new Node();
            t->data = arr[i];
            t->left = t->right = NULL;
            p->right = t;
            p = t;
        } else {
            pop(&st);
        }
    }
}


int main() {
    int res;
    iterative_insertion(root, 50);
    iterative_insertion(root, 40);
    iterative_insertion(root, 60);
    // recursive_insertion(root, 50);
    // recursive_insertion(root, 40);
    // recursive_insertion(root, 60);
    // res = iterative_search(root, 60);
    // cout<<"Found - > "<<res<<endl;
    // res = recursive_search(root, 40);
    // cout<<"Found - > "<<res<<endl;
    in_order(root);
    cout<<"-------------"<<endl;
    recursive_delete(root, 60);
    in_order(root);
    return 0;
}