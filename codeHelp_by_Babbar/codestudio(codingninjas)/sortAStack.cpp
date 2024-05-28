#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// SC - O(n2) and TC - O(n)
void insertElementAtDescendingOrder(stack<int> stack, int element) {

    // base condition either empty stack or element insert condition fulfilled
    if(stack.empty() || stack.top() <= element) {
        stack.push(element);
        return ;
    }

    // pop the top element of the stack
    int topElement = stack.top();
    stack.pop();

    // insert the element in descending order in the stack recusrisvely.
    insertElementAtDescendingOrder(stack, element);

    // re-push the element when returning from recusrsive call.
    stack.push(topElement);
}

void sortAStack(stack<int> &stack) {
    // base condition
    if(stack.empty()) {
        return;
    }

    // pop element
    int topElement = stack.top();
    stack.pop();

    // move at the bottom of the stack
    sortAStack(stack);

    // insert element at its position in descending order.
    insertElementAtDescendingOrder(stack, topElement);
}

int main() {
    int num;
    cin>>num;
    return 0;
}


