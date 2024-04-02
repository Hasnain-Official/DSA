#include<iostream>
#include<vector>

using namespace std;

void solve(string &str, int index, string output, vector<string>& ans) {
    // base condition
    if(index >= str.length()) {
        ans.push_back(output);
        return ;
    }

    // character traversal
    for(int i = index; i < str.length(); i++) {
        output.push_back(str[i]);
        solve(str, index+1, output, ans);
        output.pop_back();
    }
}

void printVector(vector<string>& arr) {
    for (auto x : arr){
        cout<<" - > "<<x<<" "<<endl;
    }
}

vector<string> permutationsOfString(string& str) {
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, index, output, ans);
    printVector(ans);
    return ans;
}



int main() {
    string s = "abc";
    permutationsOfString(s);
    return 0;
}