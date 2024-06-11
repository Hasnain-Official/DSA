#include<iostream>
#include<vector>
#include<map>

using namespace std;


// Time - nlogn : n is traversing of vector and ordered map insertion nlogn
// Space complexity : O(n)
vector<int> relativeSortArray(vector<int> arr1, vector<int> arr2) {
        map<int, int> omap;
        vector<int> res;
        // ascending order elements stored
        for(int i  = 0; i < arr1.size(); i++) {
            omap[arr1[i]] = omap[arr1[i]] ? ++omap[arr1[i]] : 1;
        }

        // traverse array 2 and push the no. of elements count in resultant vector
        for(int i = 0; i < arr2.size(); i++) {
            while(omap[arr2[i]] > 0) {
                res.push_back(arr2[i]);
                omap[arr2[i]] = omap[arr2[i]]-1;
            }
        }

        // traverse to the left key value and insert them into res vector, already ordered because we use ordered map
        for(auto it:omap) {
            while(it.second > 0) {
                res.push_back(it.first);
                it.second--;
            }
        }
        return res;
}

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<" - > "<<i<<" "<<arr[i]<<endl;
    }
}

int main() {
    vector<int> a1 = {2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31};
    vector<int> a2 = {2,42,38,0,43,21};
    vector<int> res = relativeSortArray(a1, a2);
    printVector(res);
    return 0;
}   