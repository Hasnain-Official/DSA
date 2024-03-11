#include<iostream>
using namespace std;


int isPossible(int arr[], int n, int m,int mid) {
    int pageSum = 0, studentCount = 0;
    for (int i = 0; i < n; i++) {
        if((pageSum + arr[i]) == mid) {
            pageSum += arr[i];
        } else {
            studentCount++;
            if((studentCount > m ) || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
        return true;
    }
    
    return -1;
}
int bookAllocation(int arr[], int n, int m) {
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int e = sum, ans = -1, mid = s + (e-s)/2;
    while(s<=e) {
        if(isPossible(arr,n, m,mid)) {
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
    return 0;
}

