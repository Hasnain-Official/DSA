#include<iostream>
#include<vector>

using namespace std;

void spiralMatrix(vector<vector<int>> ar, int rows, int columns) {
    int count = 0;
    int total = rows*columns;
    vector<int> ans;

    // index inititalizations
    int startingRow = 0, startingColumn = 0, endingRow = rows-1, endingColumn = columns-1;
    while(count < total) {

        // print starting row
        for (int i = startingColumn; count < total && i <= endingColumn; i++) {
            ans.push_back(ar[startingRow][i]);
            count++;
        }
        startingRow++;

        // print ending column
        for (int i = startingRow; count < total && i <= endingRow; i++) {
            ans.push_back(ar[i][endingColumn]);
            count++;
        }
        endingColumn--;
        
        //print ending row
        for (int i = endingColumn; count < total && i >= startingColumn; i--) {
            ans.push_back(ar[endingRow][i]);
            count++;
        }
        endingRow--;

        // print starting column
        for (int i = endingRow; count < total && i >= startingRow; i--) {
            ans.push_back(ar[i][startingColumn]);
            count++;
        }
        startingColumn++;
    }

    for (int x : ans) {
        cout<<x<<" ";
    }
    
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
    spiralMatrix(ar, rows, cols);
}