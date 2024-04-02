#include<iostream>
#include<vector>

using namespace std;

bool checkEqual(vector<int> c1, vector<int> c2) {
    for (int i = 0; i < c1.size(); i++) {
        if(c1[i] != c2[i]) {
            return false;
        }
    }
    return true;
}

bool permutationString(string s, string part) {
    vector<int> c1(26, 0), c2(26,0);
    int i = 0;
    while(i < part.length()) {
        int index = part[i] - 'a';
        c1[index]++;
        i++;
    }
    
    i = 0;
    int windowSize = part.length();
    while(i < windowSize && i < s.length()) {
        int index = s[i] - 'a';
        c2[index]++;
        i++;
    }
    if(checkEqual(c1, c2)) {
        return true;
    }

    while(i < s.length()) {
        c2[(s[i-windowSize]-'a')]--;
        c2[s[i]-'a']++;
        i++;
        if(checkEqual(c1,c2)) {
            return true;
        }
    }
    return false;
}

int main() {
    string s = "eidbaooo";
    string part = "ab";
    bool exists = permutationString(s, part);
    cout<<" - > "<<part<<" "<<exists<<endl;
    return 0;
}