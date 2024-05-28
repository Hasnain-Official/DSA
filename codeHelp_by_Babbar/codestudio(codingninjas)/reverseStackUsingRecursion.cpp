#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// SC - O(n2) and TC - O(n)
void insertAnElementAtItsBottomInAStack(stack<int> &myStack, int x) {
      // base condition 
    if(myStack.empty()) {
        myStack.push(x);
        return ;
    }

    // get the top element
    int topElement = myStack.top();

    // remove the top element
    myStack.pop();

    // recusively get the end of the condition
    insertAnElementAtItsBottomInAStack(myStack, x);

    // push back the elment which was poped 
    myStack.push(topElement);
}

void solve(stack<int> &stack) {

    // base condition
    if(stack.empty()) {
        return;
    }

    int topElement = stack.top();
    stack.pop();
    solve(stack);
    insertAnElementAtItsBottomInAStack(stack, topElement);
}

void reverseStackUsingRecursion(stack<int> &stack) {
    if(stack.empty()) {
        return;
    }

    solve(stack);
}

int main() {
    int num;
    cin>>num;
    return 0;
}


