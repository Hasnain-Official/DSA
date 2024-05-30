#include<iostream>
#include<stack>

using namespace std;

/*
Approach : 
    - Push all the elements into stack.
    - get the top most element and check a knows b or vice versa
    - whichever doesn't know other push that element who doesn't know.
    - check for the element left into stack, it's rows and columns.
    - if matches, rows are 0 and columns are 1 of the element, then return true otherwise false

Catch : 
    - The Celebrity knows no one, means rows are 0.
    - Ordinary person knows the celebrity, means column must have 1 for the celebrity.
    - Exclude in each condition row == column it will be 0.

Intuition : 
    - Try to use bruteforce approach but TC will be O(n2).
    - Let's try a data structure to check it works or not
    - Why not stack to push all the elements and compare the elements whether element a knows b or vice versa.
    - Now apply the above approach and catch to move further.
*/

bool knows(vector<vector<int>> &M, int a, int b) {
    bool resp = false;
    if(M[a][b] == 1) resp = true;
    return resp; 
}

int celebrityProblem(vector<vector<int>> &M, int n) {
    stack<int> s;

    // push all the elements in stack
    for(int i = 0; i < n; i++) {
        s.push(i);
    }

    // pop the top 2 elements from stack until stack has only 1 element left
    while(s.size() > 1) {

        // pop the first element at top of stack
        int a = s.top();
        s.pop();

        // pop the second element at top of stack
        int b = s.top();
        s.pop();

        // check for the if a knows b, if true, then push the b back into stack
        if(knows(M,a,b)) {
            s.push(b);
        } else {
            // else if b knows a then push a back into stack
            s.push(a);
        }
    }

    int candidate = s.top();
    // check for the rows of the element left into stack if all the rows are 0 or not except i == j
    bool checkRow = false, zeroCount = 0;
    for(int i = 0; i < n; i++) {
        if(M[candidate][i] == 0 && candidate != i) zeroCount++; 
    }

    // if zeroCount is n-1 that means row at every column (excluding diagonal index) is 0
    if(zeroCount == n-1) {
        checkRow = true;
    }

    // check for the columns of the element left into stack if all the columns are 1 or not except i == j
    bool checkCol = false, oneCount = 0;
    for(int i = 0; i < n; i++) {
        if(M[i][candidate] == 1 && candidate != i) oneCount++;
    }

    // if oneCount is n-1 that means column at every row (excluding diagonal index) is 1
    if(oneCount == n-1) {
        checkCol = true;
    }

    // if row and columns are checked based on them return the response.
    return (checkRow && checkCol) ? true : false;
}

int main() {
    return 0;
}