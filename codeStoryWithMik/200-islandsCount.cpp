#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j, int row, int col) {
  if(i < 0 || i > row || j < 0 || j < col || grid[i][j] != '1' || grid[i][j] == '$') {
    return ;
  }
  grid[i][j] = '$';

  // traverse the other horizontal and vertical space
  dfs(grid, i+1, j, row, col);
  dfs(grid, i-1, j, row, col);
  dfs(grid, i, j+1, row, col);
  dfs(grid, i, j-1, row, col);
}

int numIslands(vector<vector<char>>& grid) {
    int row = grid.size(), col = grid[0].size(), islands = 0;
    int i = 0;
    while (i < row) {
      int j = 0;
      while (j < col) {
        if(grid[i][j] == 1) {
          dfs(grid, i, j, row, col);
          islands++;
        }
        j++;
      }
      i++;
    }
    return islands;
}

int main() {
  vector<vector<char>> grid = {
    {'1', '1', '1', '1', '0'},
    {'1', '1', '0', '1', '0'},
    {'1', '1', '0', '0', '0'},
    {'0', '0', '0', '0', '0'}
  };
  cout<<"- > "<< numIslands(grid)<<endl;
  return 0;
}