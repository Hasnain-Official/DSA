#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout<<" - > "<<i<<" "<<j<<" "<<arr[i][j]<<endl;
        }
    }
}

bool binarySearch2dArray(vector<vector<int>> matrix, int rows, int columns, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int start = 0, end = (row*col)-1;
    int mid = start + (end - start)/2;
    while(start <= end) {
        int ele = matrix[mid/col][mid%col];
        if(ele == target) {
            return true;
        }
        if(ele < target) {
            start = mid + 1;
        } else if(ele > target) {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return false;
    // printVector(ans);
}

int main() {
    vector<vector<int>> ar;
    int rows, cols, ele;
    // cout<<"Enter no. of rows : "<<endl;
    // cin>>rows;
    // cout<<"Enter no. of columns : "<<endl;
    // cin>>cols;
    // for(int i = 0; i < rows;i++)  {
    //     for (int j = 0; j < cols; j++) {
    //         cin>>ar[i][j];
    //     }
    // }
    ar = {{1,2,3},{4,5,6},{7,8,9}};
    rows = 3;
    cols = 3;
    ele = 10;
    binarySearch2dArray(ar, rows, cols, ele);
}