#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int>& nums, int index, vector<int> output, vector<vector<int>>& ans) {
    if(index >= nums.size()) {
        ans.push_back(output);
        return ;
    }

    // exclude
    solve(nums, index+1, output, ans);

    //include
    int ele = nums[index];
    output.push_back(ele);
    solve(nums, index+1, output, ans);
}

void printVector(vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout<<" - > "<<i<<" "<<j<<" "<<arr[i][j]<<endl;
        }
    }
}


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, 0, output, ans);
    printVector(ans);
    return ans;
}



int main() {
    vector<int> arr1;
    arr1 = {1,2,3};
    // arr2 = {6,2,8,4,10};
    // int pos = 3;
    subsets(arr1);
    // printVector(arr1);
    return 0;
}