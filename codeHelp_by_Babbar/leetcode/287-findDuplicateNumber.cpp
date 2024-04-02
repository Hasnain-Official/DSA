#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//  int findDuplicate(vector<int>& nums) {
//         unordered_map<int, int> um;
//         int i = 0;
//         while(i < nums.size()) {
//             if(um[nums[i]]) {
//                 um[nums[i]] += 1;
//             } else {
//                 um[nums[i]] = 1;
//             }
//             i++;
//         }
//         int duplicate = 0;
//         i = 0;
//         for(auto x : um) {
//             if(x.second > 1) {
//                 duplicate = x.first;
//             }
//         }
//         return duplicate;
//     }


    // 442 - findAllDuplicate
    // method 2 -->  i < nums[i] < n  // hint : numbers in array will be lie in range i to n
    int dupli(vector<int> &nums) {
        int i = 0, n = nums.size();
        vector<int> v;
        while(i < n) {
            int num = abs(nums[i]);
            int index = num - 1;
            if(nums[index] < 0) {
                v.push_back(num);
            } else {
                nums[index] *= -1;
            }
            i++;
        }

        for(auto x : v) {
            cout<<x<<" ";
        }
        return 0;
    }


int main() {
    vector<int> arr;
    arr = {4,3,2,7,8,2,3,1};
    // cout<<"Number of One's : "<<findDuplicate(arr)<<endl;
    cout<<"Number of One's : "<<dupli(arr)<<endl;
    return 0;
}