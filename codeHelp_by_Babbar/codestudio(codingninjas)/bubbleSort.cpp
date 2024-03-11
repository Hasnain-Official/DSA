#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<" - > "<<i<<" "<<arr[i]<<endl;
    }
}

void bubbleSort(vector<int> arr) {
    for (int i = 0; i < arr.size()-1; i++) {
        bool swapped = false;
        for (int j = 0; j < arr.size()-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
    }
    printVector(arr);
}

// space complexity - O(1)
// time complexity - best case - O(n) and worst case - O(n2)
// bubble sort is in-place algorithm
// in-place : algoruithm which does not take extra spcae to give output

int main() {
    vector<int> arr;
    arr = {6,2,8,4,10};
    bubbleSort(arr);
    return 0;
}