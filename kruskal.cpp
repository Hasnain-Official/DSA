#include<iostream>
using namespace std;
const int I = INT_MAX;

int edges[3][9] = {
    {1,1,2,2,3,4,4,5,5},
    {2,6,3,7,4,5,7,6,7},
    {25,5,12,10,8,16,14,20,18}
}; 
int set[8] = {-1};
int included[9] = {0};
int t[2][6];

// Join the vertices using disjoint subsets
void Union(int u, int v) {
    if(set[u] < set[v]) {
        set[u] = set[u] + set[v];
        set[v] = u;
    } else {
        set[v] = set[u] + set[v];
        set[u] = v;
    }
};

// find the parent of the vertex
int find(int u) {
    int x = u;
    while (set[x] > 0) {
        x = set[x];
    }
    return x;
}

int main() {
    int i, j, k, u, v, min = I, n =7, e =9;
    i = 0; 
    while (i < n -1) {
        min = I;

        // find the minimum weight edges
        for(j = 0; j < e; j++) {
            if(included[j] == 0 && edges[2][j] < min) {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }

        // check the parent of indexes forming cycle
        if(find(u) != find(v)) {
            t[0][i] = u;
            t[1][i] = v;
            Union(find(u),find(v));
            i++;
        }

        // update the included value in array whether its forming a cycle or not
        included[k] = 1;
    }

    // print the vertices of the graph formed
    for (i = 0; i < n-1; i++) {
        cout<<" - > ( "<<t[0][i]<<", "<<t[1][i]<<" )"<<endl;
    }
}