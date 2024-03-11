#include<iostream>
using namespace std;

int isPossible(int arr[], int n, int m, int mid) {
    int paintersCount = 0, pageSum = 0;
    for (int i = 0; i < n; i++) {
        if((pageSum + arr[i] == mid)) {
            pageSum += arr[i];
        } else {
            paintersCount++;
            if(paintersCount > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int painterPartition(int arr[], int n, int m) {
    int ans = 0;
    int sum = 0, s = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s)/2;
    while (s <= e) {
        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    
    return ans;
}

int main() {
    int arr[] = {5,5,5,5};
    int size = 4;
    int noOfPainters = 2;
    cout<<painterPartition(arr, size, noOfPainters)<<endl;
    return 0;
}