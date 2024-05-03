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


// farmland starting position by default the index of 1 in land vector, last position will be the bootom right of the farmland
void dfs(vector<vector<int>> land, int i, int j, int& r1, int& c1, int &r2, int &c2, int rows, int cols) {
    if(i < 0 || i >= rows || j < 0 || j >= cols || land[i][j] == 0) {
        return ;
    }

    r2 = max(r2, i);
    c2 = max(c2, j);

    land[i][j] = 0;

    // traverse horizontally and vertically
    dfs(land, i+1, j, r1, c1, r2, c2, rows, cols);
    dfs(land, i-1, j, r1, c1, r2, c2, rows, cols);
    dfs(land, i, j+1, r1, c1, r2, c2, rows, cols);
    dfs(land, i, j-1, r1, c1, r2, c2, rows, cols);
};

vector<vector<int>> noOfFarmLands(vector<vector<int>> land, int rows, int cols) {
    vector<vector<int>> res;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(land[i][j] == 1) {
                int r1 = i, c1 = j, r2 = -1, c2 = -1;
                dfs(land, i, j, r1, c1, r2, c2, rows, cols);
                res.push_back({r1, c1, r2, c2});
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> res;
    vector<vector<int>> land = {
        {1,0,0},
        {0,1,1},
        {0,1,1}
    };
    res = noOfFarmLands(land, 3, 3);
    printVector(res);
    return 0;
}