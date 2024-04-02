#include<iostream>
#include<vector>

using namespace std;

void solve(string s, int index, string output, vector<string>& ans) {
    //base condition
    if(index == s.length()) {
        ans.push_back(output);
        return ;
    }

    //exclude condition
    solve(s, index+1, output, ans);

    // include condition
    char ele = s[index];
    output += ele;
    solve(s, index+1, output, ans);
}

void printVector(vector<string>& arr) {
    for (auto x : arr){
        cout<<" - > "<<x<<" "<<endl;
    }
}

vector<string> subsequencesofString(string s) {
    vector<string> ans;
    string output;
    int index = 0;
    solve(s, 0, output, ans);
    printVector(ans);
    return ans;
}



int main() {
    string s;
    s = "abc";
    // arr2 = {6,2,8,4,10};
    // int pos = 3;
    subsequencesofString(s);
    // printVector(arr1);
    return 0;
}