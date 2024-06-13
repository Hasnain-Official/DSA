#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

void reverseFirstKElementsOfQueue(queue<int> &q, int k) {
    // put elements into stack
    int i = 0;
    stack<int> s;
    while (i < k) {
        s.push(q.front());
        q.pop();
        i++;
    }

    // push the reversed elements from stack to queue
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // reverse the left out elements which are on front, send them to back.
    i = q.size() - k;
    while(i > 0) {
        int ele = q.front();
        q.pop();
        q.push(ele);
        i--;
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);


    reverseFirstKElementsOfQueue(q, 4);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}