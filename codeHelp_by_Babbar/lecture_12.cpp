#include<iostream>
#include<vector>

using namespace std;

// Binary Search
int binarySearch(vector<int> arr, int key) {
    if(key >= INT_MAX || key <= INT_MIN) {
        return -1;
    }
    int start = 0;
    int end = arr.size() - 1;
    // int mid = (start + end)/2;
    int mid = start + (end - start)/2;
    while(start <=end) {
        if(arr[mid] == key) {
            return mid;
        }
        if(key < arr[mid]) {
            end = mid - 1;
        }
        if(key > arr[mid]) {
            start = mid+1;
        }
        // mid = (start + end)/2;
        mid = start + (end - start)/2;
    }
    return -1;
}


int main() {
    return 0;
}
