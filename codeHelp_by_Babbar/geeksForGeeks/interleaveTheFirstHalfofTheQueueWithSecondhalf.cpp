#include<iostream>
#include<queue>
#include<stack>

using namespace std;



// can be achieved if i put half elements in stack then put the elements in queue
// then make the other half elements re insert at the back of queue
// so the first half again push into stack
// now the order will be reversed into stack
// one by one take first element from stack and other from front of queue
// insert them one by one
// in next step take top elements again like before and push them into stack 

class Solution {
    private:

        // This function solve has SC - O(n) and TC - O(n)
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
    public:
        queue<int> interleaveTheFirstHalfofTheQueueWithSecondhalf(queue<int> &q) {
            int size = q.size();
            stack<int> s;
            int i = 0;
            while(!q.empty() && i < size/2) {
                int ele = q.front();
                q.pop();
                solve(s, ele);
                i++;
            }
            int stackSize = s.size();

            while(!s.empty()) {
                int topEle = s.top();
                s.pop();
                q.push(topEle);

                topEle = q.front();
                q.pop();
                q.push(topEle);
            }

            return q;
        }
};


int main() {
     queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    Solution *s = new Solution();
    s->interleaveTheFirstHalfofTheQueueWithSecondhalf(q);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}