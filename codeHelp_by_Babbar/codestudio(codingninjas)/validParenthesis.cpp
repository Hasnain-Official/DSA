#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool matches(char top, char charac) {
    bool matched = false;
    if(
        (top == '(' && charac == ')') ||
        (top == '{' && charac == '}') || 
        (top == '[' && charac == ']')
    ) {
        matched = true;
    } 
    return matched;
}

bool isValidParenthesis(string expression) {
    stack<int> s;
    for(int i = 0; i < expression.length(); i++) {

        // exp[i] is {, [, ( then push
        if(expression[i] == '{' || expression[i] == '[' || expression[i] == '(') s.push(expression[i]);

        // on closing bracket pop the element from stack
        else {

            // if stack is empty the not a valid parenthesis
            if(s.empty()) {
                return false;
            } else {
                int top = s.top();

                // match the stack top element and the closing bracket
                if(matches(top, expression[i])) {
                    s.pop();
                } else {
                    return false;
                }
            }
        }
    }
    if(s.empty()) return true;
    else return false;
}

int main() {

    string expression = "{{}[]()}";
    bool res = isValidParenthesis(expression);
    cout<<"Is Valid Parenthesis - > "<<res<<endl;
    return 0;
}


