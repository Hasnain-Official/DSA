#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<" - > "<<i<<" "<<arr[i]<<endl;
    }
}

void noOfZeroes(vector<int> &arr) {
    int i = 0,j = 0;
    while(j < arr.size()) {
        if(arr[j] != 0) {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    
}

int main() {
    vector<int> arr1, arr2, arr3;
    arr1 = {0,6,0,2,8,0,10,0};
    noOfZeroes(arr1);
    printVector(arr1);
    return 0;
}