#include<iostream>
#include<stack>

using namespace std;

/**
  Catch - if the stack top contains the operator then its not redundant otherwise it is redundant character.
*/
// ((a+b)) - unwanted brackets
bool findRedundantBrackets(string &str) {
    stack<char> s;

    // traverse the string
    for(int i = 0; i < str.length(); i++) {

        // push into stack in case character matches
        if(str[i] == '(' || 
            str[i] == '+' ||
            str[i] == '-' ||
            str[i] == '*' ||
            str[i] == '/'
        ) {
            s.push(str[i]);
        } else {
            // pop the element if closing bracket found
            if(str[i] == ')') {
                bool isRedundant = true;

                // traeverse the stack for the matching bracket.
                while (s.top() != '(') {
                    char top = s.top();
                    if(top == '+' ||
                        top == '-' ||
                        top == '*' ||
                        top == '/'
                    ) {
                       isRedundant = false; 
                    }
                    s.pop();
                }
                if(isRedundant == true) return true;

                // pop the element
                s.pop();
            }
        }
    }
    return false;
}

int main() {
    return 0;
}