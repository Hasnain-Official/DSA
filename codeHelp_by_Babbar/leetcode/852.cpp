#include<iostream>
#include<vector>

using namespace std;

// can be done by finding max in O(n)
// use binary search for the O(logn) 

int peak(vector<int> arr) {
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s)/2;
    while(s < e) {
        if(arr[mid] < arr[mid+1]) {
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
}

int main() {
    vector<int> arr;
    int n, val;
    cout<<"Enter the Size of Array : "<<endl;
    cin>>n;
    cout<<"Enter Elements in Array : "<<endl;
    for (int i = 0; i < n; i++) {
        cin>>val;
        arr.push_back(val);
    }
    cout<<" - > "<<peak(arr)<<endl;
    return 0;
}