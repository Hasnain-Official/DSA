#include<iostream>
#include<vector>
#include<stack>

using namespace std ;

string revStr(string str) {
    string revStr = "";
    stack<char> s;

    for(int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    while (!s.empty()) {
        revStr.push_back(s.top());
        s.pop();
    }
    return revStr;
}

int main() {

    string str = "russia";
    
    cout<<revStr(str)<<endl;

    return 0;
}


