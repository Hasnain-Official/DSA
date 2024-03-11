#include<iostream>
#include<vector>

using namespace std;

int firstOcc(vector<int> arr, int key) {
    int start = 0, end = arr.size();
    int mid = start + (end - start)/2, ans = -1;
    while(start <= end) {
        if(arr[mid] < key) {
            end = mid -1;
        }
        if(arr[mid] > key) {
            start = mid + 1;
        }
        if(arr[mid] == key) {
            ans = mid;
            end = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int lastOcc(vector<int> arr, int key) {
    int start = 0, end = arr.size() - 1;
    int mid = start + (end - start)/2, ans = -1;
    while(start <= end) {
        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        }
        if(arr[mid] < key) {
            end = mid - 1;
        }
        if(arr[mid] > key) {
            start = mid + 1;
        }
        mid = start + (end - start)/2;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    }
    return ans;
}

int main() {
    pair<int,int> p;
    vector<int> arr;
    int n, val;
    cout<<"Enter the Size of array : "<<endl;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>val;
        arr.push_back(val);
    }
    
    int key;
    cout<<"Enter Target Value : "<<endl;
    p.first = firstOcc(arr, key);
    p.second = lastOcc(arr, key);
    cout<<" - > "<<p.first<<" "<<p.second<<endl;
    return 0;
}