#include<iostream>
#include<vector>

using namespace std;

string removeAllSubstring(string s, string part) {
    while(s.length() != 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main() {
    string s = "dabbdabbssookokoklop";
    string part = "abb";
    s = removeAllSubstring(s, part);
    cout<<" - > "<<s<<endl;
    return 0;
}