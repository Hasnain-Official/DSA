#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<" - > "<<i<<" "<<arr[i]<<endl;
    }
}

void rotateArray(vector<int> arr, int pos) {
    int i = 0;
    vector<int> temp(arr.size());
    while (i < arr.size()) {
        // swap(arr[(i+pos)%arr.size()], arr[i]);
        temp[(i+pos)%arr.size()] = arr[i];
        i++;
    }
    arr = temp;
    printVector(arr);
}

int main() {
    vector<int> arr;
    // arr = {6,2,8,4,10};
    arr = {1,2,3,4,5,6,7};
    int pos = 3;
    rotateArray(arr, pos);
    return 0;
}