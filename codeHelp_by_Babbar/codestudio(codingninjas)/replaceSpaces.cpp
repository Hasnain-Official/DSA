#include<iostream>
#include<vector>

using namespace std;

string replaceSpaces(string s) {
    int i = 0;
    string replacement = "@40";
    vector<string> temp;
    while(i < s.length()) {
        if(s[i] == ' ') {
            // temp.push_back(replacement);
            s.replace(i, 1, replacement);
        } 
        // else {
        //     temp.push_back(string(1,s[i]));
        // }
        i++;
    }
    return s;
}

int main() {
    // vector<string> m = replaceSpaces("my Name is khan");
    // for(auto a : m) {
    //     cout<<" - > "<<a<<endl;
    // }
    cout<<replaceSpaces("My name is Khan")<<endl;
    return 0;
}