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

void rotateImage(vector<vector<int>> matrix, int rows, int columns) {
    int row = matrix.size(), col = matrix[0].size();
    vector<vector<int>> ans(row, vector<int>(col));
    int i = 0, colCount = col-1;
    while(i < row) {
        int j = 0;
        while(j < col) {
            ans[j][colCount] = matrix[i][j];
            j++;
        }
        i++;
        colCount--;
    }
    // matrix = ans;
    printVector(ans);

   
}

int main() {
    vector<vector<int>> ar;
    int rows, cols;
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
    rotateImage(ar, rows, cols);
}