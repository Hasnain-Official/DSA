#include<iostream>
#include<vector>

using namespace std;

int getPivot(vector<int> arr) {
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s)/2;
    while (s < e) {
        if(arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
}

int binarySearch(vector<int> arr, int s, int e, int key) {
    if(key >= INT_MAX || key <= INT_MIN) {
        return -1;
    }
    int start = s;
    int end = e - 1;
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


int sqrt(int val) {
    int start = 0;
    int end = val;
    int mid = start + (end - start)/2;
    int ans = -1;
    while (start <= end) {
        long long int sq = mid * mid;
        if(sq == val) {
            return mid;
        }
        if(sq < val) {
            ans = mid;
            start = mid + 1;
        }
        if(sq > val) {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

double precision(int n, int precision, int tempRes) {
    int factor = 1;
    int ans = tempRes;
    for (int i = 0; i < precision; i++) {
        factor = factor/10;
        for (int j = ans; j*j < n; j = j + factor) {
            ans = j;
        }
    }
    return ans;
}


int main() {
    int n, key, val;
    // cout<<"Enter the Size of Array : "<<endl;
    // cin>>n;
    // vector<int> arr;
    // for (int i = 0; i < n; i++) {
    //     cin>>val;
    //     arr.push_back(val);
    // }
    // cout<<"Enter Key to be searched : "<<endl;
    // cin>>key;
    // int pivot = getPivot(arr);
    // int start = 0, end = arr.size() - 1;
    // if(key > pivot && key < end) {
    //     cout<<" - > "<<binarySearch(arr, pivot, end, key)<<endl;;
    // } else {
    //     cout<<" - > "<<binarySearch(arr, start, pivot, key)<<endl;
    // }
    cout<<"Enter the number to find square root : "<<endl;
    cin>>n;
    int tempRes = sqrt(n);
    cout<<"TEMP RES - "<<tempRes<<endl;
    tempRes = precision(n, 3, tempRes);
    cout<<"RES - "<<tempRes<<endl;
    return 0;
}