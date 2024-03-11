#include<iostream>
#include<vector>

using namespace std;

vector<int> pairSum(vector<int> arr, int target){
    vector<vector<int>> ans;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i+1; j < arr.size(); j++) {
            if((arr[i] + arr[j]) == target) {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
}

void printArray(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n, a;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;
    // int *b = new int[n];
    cout<<"Enter Target - "<<endl;
    int target;
    cin>>target;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        // cin>>b[i];
        cin>>a;
        b.push_back(a);
    }

    pairSum(b, target);
    return 0;
}