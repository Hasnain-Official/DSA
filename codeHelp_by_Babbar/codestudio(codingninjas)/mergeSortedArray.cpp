#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void mergeSorted(vector<int> arr1, vector<int> arr2, vector<int> arr3) {
    int i = 0, j = 0, k = 0, n = arr1.size(), m = arr2.size();
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) {
            arr3.push_back(arr1[i]);
            i++;
            k++;
        } else {
            arr3.push_back(arr2[j]);
            j++;
            k++;
        }
    }
    while(i < n) {
        arr3[k++] = arr1[i++];
    }
    while(j < m) {
        arr3[k++] = arr2[j++];
    }
}

int main() {
    vector<int> arr1, arr2, arr3;
    arr1 = {6,2,8,4,10};
    arr2 = {6,2,8,4,10};
    int pos = 3;
    return 0;
}