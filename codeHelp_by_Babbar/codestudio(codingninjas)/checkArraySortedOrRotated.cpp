#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<" - > "<<i<<" "<<arr[i]<<endl;
    }
}

bool checkSortedOrRotated(vector<int> arr) {
    int count = 0;
    for (int i = 1; i < arr.size(); i++) {
        if(arr[i-1] > arr[i]) {
            count++;
        }
    }
    if(arr[arr.size() - 1] <arr[0]) {
        count++;
    }
    return count <= 1;
}

int main() {
    vector<int> arr;
    // arr = {6,2,8,4,10};
    arr = {1,2,3,4,5,6,7};
    int pos = 3;
    cout<<checkSortedOrRotated(arr)<<endl;
    return 0;
}