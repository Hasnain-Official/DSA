#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// TC - O(n) and SC - O(n)

queue<int> queueReversal(queue<int> q) {
    stack<int> s;
    while(!q.empty()) {
        int ele = q.front();
        q.pop();
        s.push(ele);
    }

    while (s.empty()) {
        int ele = s.top();
        s.pop();
        q.push(ele);
    }
    return q;
}

void solve(queue<int> &q) {
    if(q.empty()) {
        return ;
    }
    int frontEle = q.front();
    q.pop();
    solve(q);
    q.push(frontEle);
}

queue<int> queueReversalUsingRecursion(queue<int> q) {
    if(q.empty()) {
        return q;
    }
    solve(q);
    return q;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    queue<int> reversedQ = queueReversalUsingRecursion(q);

    while (!reversedQ.empty()) {
        cout << reversedQ.front() << " ";
        reversedQ.pop();
    }

    return 0;
}