#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

char maximumOccurringCharater(vector<char> ch) {
    unordered_map<char, int>  m;
    int i = 0, noOfTimes = 0;
    char maxChar = '0';
    while(i < ch.size()) {
        if(m[ch[i]]) {
            m[ch[i]] = m[ch[i]] + 1;
        } else {
            m[ch[i]] = 1;
        }
        i++;
    }
    for(auto i : m) {
        if(i.second > noOfTimes) {
            noOfTimes = i.second;
            maxChar = i.first;
        }
    }
    // cout<<maxChar<<" "<<noOfTimes<<endl;
    return maxChar;
}

int main() {
       vector<char> ch = {'a','b','c','d','d'};

    // Print the characters in the vector
    for (char c : ch) {
        cout << c;
    }
    cout << endl;
    cout<<"- > "<<maximumOccurringCharater(ch)<<endl;
    return 0;
}
