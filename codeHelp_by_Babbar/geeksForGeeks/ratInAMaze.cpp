#include<iostream>
#include<vector>

using namespace std;

// check next step so that the rat moves safely
bool isSafe(vector<vector<int>> m, int n, int x, int y, string path, vector<vector<int>>& visited) {
    if((x > 0 && x < n) && (y > 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    } else { 
        return false;
    }
}

void solve(vector<vector<int>> m, int n, int x, int y, string path, vector<vector<int>>& visited, vector<string>& ans) {
    if(x == n-1 || y == n-1) {
        ans.push_back(path);
        return ;
    }

    // mark the visited path so that when it return it will be easier in backtracking
    visited[x][y] = 1;

    // 4 choices - D, L, R, U
    // Down
    int newx = x+1;
    int newy = y;
    if(isSafe(m,n,newx,newy, path, visited)) {
        path.push_back('D');
        solve(m, n, newx, newy, path, visited, ans);
        path.pop_back();
    }

    // Left
    newx = x;
    newy = y-1;
    if(isSafe(m, n, newx, newy, path, visited)) {
        path.push_back('L');
        solve(m, n, newx, newy, path, visited, ans);
        path.pop_back();
    }

    // Right
    newx = x;
    newy = y+1;
    if(isSafe(m, n, newx, newy, path, visited)) {
        path.push_back('R');
        solve(m, n, newx, newy, path, visited, ans);
        path.pop_back();
    }

    // Up
    newx = x-1;
    newy = y;
    if(isSafe(m, n, newx, newy, path, visited)) {
        path.push_back('U');
        solve(m, n, newx, newy, path, visited, ans);
        path.pop_back();
    }

    // umark the visited path so that when backtracking new path can be found out, so mark the taken sep back to 0.
    visited[x][y] = 0;
}

vector<string> ratInAMaze(vector<vector<int>> &m, int n) {
    vector<string> ans;
    string path;
    int srcx = 0;
    int srcy = 0;
    vector<vector<int>> visited(n, vector<int>(n,0));
    if(m[0][0] == 0) {
        return ans;
    }
    solve(m, n, srcx, srcy, path, visited, ans);
    return ans;
}

int main() {
    return 0;
}