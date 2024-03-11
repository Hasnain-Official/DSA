#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<" - > "<<i<<" "<<arr[i]<<endl;
    }
}

vector<int> reverse(vector<int> arr) {
    int s = 0;
    int e = arr.size();
    while(s <= e) {
        swap(arr[s++], arr[e--]);
    }
    return arr;
}

vector<int> sumOfTwoArrays(vector<int> arr1, vector<int> arr2) {
    int i = arr1.size()-1, j = arr2.size()-1, carry = 0;
    vector<int> ans;
    while(i != 0 && j != 0) {
        int sum = arr1[i] + arr2[j] + carry;
        carry = sum /10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while(i >= 0 ) {
        int sum = arr1[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    while(j >= 0 ) {
        int sum = arr2[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }
    while(carry != 0 ) {
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    return reverse(ans);
}

int main() {
    vector<int> arr, arr2;
    arr = {6,2,8,4,10};
    arr2 = {1,2,3,4,5,6,7};
    int pos = 3;
    printVector(sumOfTwoArrays(arr, arr2));
    return 0;
}