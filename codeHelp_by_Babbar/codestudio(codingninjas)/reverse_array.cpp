#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<" - > "<<i<<" "<<arr[i]<<endl;
    }
}

vector<int> reverseOrder(vector<int> arr, int pos) {
    int s = pos, e = arr.size() -1;
    while(s <= e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    return arr;
}

int main() {
    vector<int> arr;
    arr = {6,2,8,4,10};
    int pos = 3;
    vector<int> ans = reverseOrder(arr, pos);
    printVector(ans);
    return 0;
}