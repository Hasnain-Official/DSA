#include<iostream>
#include<queue>
using namespace std;

queue<int> q;

void bfs(int G[7][7], int start, int n) {
    int i = start, j;
    int visited[7] = {0};
    visited[i] = 1;
    q.push(i);
    cout<<" - > "<<i<<endl;
    while (!q.empty()) {
        i = q.front();
        q.pop();
        for (j = 1; j <= n; j++) {
            if(G[i][j] == 1 && visited[j] == 0) {
                cout<<" - > "<<j<<endl;
                visited[j] = 1;
                q.push(j);
            }
        }   
    }
}

void dfs(int G[][7], int start, int n) {
    static int visited[7] = {0};
    if(visited[start] == 0) {
        visited[start] = 1;
        cout<<" - > "<<start<<endl;
        for (int i = 0; i < n; i++) {
            if(G[start][i] == 1 && visited[i] == 0) {
                dfs(G, i, n);
            }
        }
    }
}

int main() {
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    // bfs(G, 4, 7);
    dfs(G, 1, 7);
    return 0;
}