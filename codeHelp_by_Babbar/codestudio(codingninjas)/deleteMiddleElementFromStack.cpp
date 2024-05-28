#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Space Complexity - O(n) and Time Complexity - O(n)
void deleteMiddleElementFromStack(stack<int> &inputStack, int N) {
    vector<int> v;
    // odd condition - (N+1)/2 th Element
    // even condition - ((N+1)/2) - 1 th Element
    int index = N&1 ? (N+1)/2 : ((N+1)/2) - 1;
    while(index < N) {
        v.push_back(inputStack.top());
        inputStack.pop();
    }
    inputStack.pop();

    for(int i = v.size() - 1; i > 0; i++) {
        inputStack.push(v[i]);
    }
}

void solve(stack<int> &inputStack, int count, int N) {
    //base condition
    if(count == N/2 && count > N) {
        inputStack.pop();
        return;
    }

    int element = inputStack.top();
    inputStack.pop();
    solve(inputStack, count+1, N);
    inputStack.push(element);
}

// SC - O(n) and TC - O(n)
void deleteMiddleElementFromStackUsingRecursion(stack<int> &inputStack, int N) {

    if(inputStack.empty()) {
        cout<<"Input Stack is Empty."<<endl;
        return ;
    }

    solve(inputStack, 0, N);

}



int main() {
    return 0;
}


