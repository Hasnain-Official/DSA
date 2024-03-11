#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<" - > "<<i<<" "<<arr[i]<<endl;
    }
}

// Method1
void selecttionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minindex = i;
        for (int j = i; j < n; j++) {
            if(arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        swap(arr[minindex], arr[i]);
    }
    printVector(arr);
}


// Method 2
void selecttionSort2(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = i; j < n; j++) {
            if(arr[j] < arr[i]) {
                swap(arr[j], arr[i]);
            }
        }
    }
    printVector(arr);
}

// Space Complexity - O(1)
// Time Complexity - O(n2) in best and worst case both
 // use case - in case of small array size
// Not a stable algorithm 
// Stable - maintain the order of same values after sorting

int main() {
    vector<int> arr;
    arr = {6,2,8,4,10};
    selecttionSort(arr);
    return 0;
}