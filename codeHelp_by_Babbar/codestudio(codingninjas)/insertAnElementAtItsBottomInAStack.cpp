#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// SC - O(n) and TC - O(n)
void solve(stack<int> &myStack, int x) {
    
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
    solve(myStack, x);

    // push back the elment which was poped 
    myStack.push(topElement);
}

void insertAnElementAtItsBottomInAStack(stack<int> &myStack, int x) {
    if(myStack.empty()) {
        myStack.push(x);
    }

    solve(myStack, x);
}

int main() {
    int num;
    cin>>num;
    return 0;
}


