#include<iostream>
#include<vector>

using namespace std;

// Phone Keypad Problem or Letter Combinations Of Phone Number

void solve(string digits, int index, string output, vector<string>& ans, vector<string> mapping) {
        // base condition
        if(index >= digits.length()) {
            ans.push_back(output);
            return ;
        }

        //  get the string of the digit at index
        int number = digits[index] - '0';
        string value = mapping[number];

        // traverse each character and make the combination
        for(int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, index+1, output, ans, mapping);
            output.pop_back();
        }
    }

void printVector(vector<string>& arr) {
    for (auto x : arr){
        cout<<" - > "<<x<<" "<<endl;
        // for(auto y : x) {
        //     cout<<" - > "<<y<<" ";
        // } cout<<endl;
    }
}

vector<string> letterCombinationOfPhoneNumber(string digits) {
    vector<string> ans;
    string output;
    int index = 0;
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if(digits.length() == 0) {
        return ans;
    }
    solve(digits, index, output, ans, mapping);
    printVector(ans);
    return ans;
}



int main() {
    string s;
    s = "23";
    // arr2 = {6,2,8,4,10};
    // int pos = 3;
    letterCombinationOfPhoneNumber(s);
    // printVector(arr1);
    return 0;
}