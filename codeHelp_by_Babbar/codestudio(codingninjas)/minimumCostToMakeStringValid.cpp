#include<iostream>
#include<stack>

using namespace std;

/**
 * Catch - in case of odd length, valid match of brackets are impossible so return -1
 * 1. always the length of string will be even
 * 2. after removing valid brackets, always: 
 *      a. left all open brackets.
 *      b. left all close brackets.
 *      c. combination of open and close but in reverse direction.
 * 3. in case of combination - still the length of open and close will be even.
 * 4. by looking closely, fomula res = (a+1)/2 + (b+1)/2;
*/
int minimumCostToMakeStringValid(string str) {
    stack<char> s;

    // odd condition - impossible to have all valid brackets
    if(str.length() % 2 == 1) return -1;

    // traverse the string
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '{') s.push(str[i]);
        else {
            // close bracket 
           if(!s.empty() && s.top() == '{') {
                s.pop();
           } else {
                // push a '}' on top of stack;
                s.push(str[i]);
           }
        }
    }

    // count the no. of open and close brackets
    int a = 0, b = 0, ans = 0;
    while(!s.empty()) {
        if(s.top() == '{') {
            a++;
        } else {
            b++;
        }
        s.pop();
    }
    // use the madeup general formula for the above condition
    ans = (a+1)/2 + (b+1)/2;
    return ans;
}

int main() {
    return 0;
}