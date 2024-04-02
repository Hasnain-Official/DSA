#include<iostream>
#include<stack>

using namespace std;

string replaceAllAdjacencyDuplicates(string s) {
    stack<char> st;
    string res = "";
    int i = 1;
    st.push(s[0]);
     while(i < s.length()) {
        if(st.empty() || st.top() != s[i]) {
            st.push(s[i]);
         } else if(st.top() == s[i]) {
            st.pop();
        }
        i++;
    }
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    
    return res;
}


// string replaceAllAdjacencyDuplicates(string s) {
//     int i = 0;
//     stack<char> st;
//     st.push('0');
//     string res = "";
//     while(i < s.length()) {
//         if(st.top() != s[i]) {
//             st.push(s[i]);
//         } 
//         i++;
//     }
//     i = 0;
//     while(!st.empty()) {
//         if(st.top() == '0') {
//             break;
//         }
//         res = st.top() + res;
//         st.pop();
//     }
//     return res;
// }

int main() {
    string s = "abbaca";
    string res = replaceAllAdjacencyDuplicates(s);
    cout<<res<<endl;
    return 0;
}