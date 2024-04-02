#include<iostream>

using namespace std;


bool isSorted(int arr[], int size) {
    if(size == 0 || size == 1) {
        return true;
    }
    if(arr[0] > arr[1]) {
        return false;
    } else {
        return isSorted(arr+1, size-1);
    }
}



// int arraySum(int arr[], int size) {
//     static int sum = 0;
//     if(size == 0) {
//         return 0;
//     }
//     // if(size == 1) {
//     //     return arr[0];
//     // }
//     arraySum(arr + 1, size - 1);
//     sum = sum + arr[0];
//     return sum;
// }

int arraySum(int arr[], int size) {
    if(size == 0) {
        return 0;
    }
    if(size == 1) {
        return arr[0];
    }
    int sum = arr[0] + arraySum(arr+1, size-1);
    return sum;
}


bool linearSearch(int arr[], int size, int search) {
    if(size == 0) {
        return false;
    }
    if(arr[0] == search) {
        return true;
    }
    return linearSearch(arr+1, size-1, search);
}


// using recursion
bool binarySearch(int arr[], int start, int end, int key) {
    int mid = start + (end-start)/2;
    if(start > end ) {
        return false;
    }
    if(arr[mid] == key) {
        return true;
    }
    if(arr[mid] < key) {
        return binarySearch(arr, mid+1, end, key);
    } else if(arr[mid] > key) {
        return binarySearch(arr, start, mid-1, key);
    }
}

int main() {
    // int arr[] = {6,2,8,4,10};
    int arr[] = {2,4,6,8,10};
    cout<<binarySearch(arr, 0, 5, 6)<<endl;
    return 0;
}
