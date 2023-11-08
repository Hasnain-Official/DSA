#include<iostream>

using namespace std;

const int I = INT_MAX;

// 8 x 8 matrix of graph
int cost[8][8] = {
    {I, I, I, I, I, I, I, I},
    {I, I, 25, I, I, I, 5, I},
    {I, 25, I, 12, I, I, I, 10},
    {I, I, 12, I, 8, I, I, I},
    {I, I, I, 8, I, 16, I, 14},
    {I, I, I, I, 16, I, 20, 18},
    {I, 5, I, I, I, 20, I, I},
    {I, I, 10, I, 14, 18, I, I},
};

// array to store nearest vertex
int near[8] = {I, I, I, I, I, I, I, I};

// array to store the minimum spanning cost vertices
int t[2][8];

int main() {
    int i ,j ,k, u, v, n = 7, min = I;

    // find the minimum cost from the cost array
    for(i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            if(cost[i][j] < min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    // insert the index of the minimum cost to t array
    t[0][0] = u;
    t[1][0] = v;

    // set the initial values of the minimum value indexes in near vertices array to 0
    near[u] = 0;
    near[v] = 0;

    // set the initial values nearest to the minimum values index
    for (i = 1; i <= n; i++) {
        if(near[i] != 0 && cost[i][u] < cost[i][v]) {
            near[i] = u;
        } else {
            near[i] = v;
        }
    }

    // repeated operations starts from here
    for(i = 1; i <=n; i++) {
        min = I;

        // find the minimum cost based on the nearest array index
        for(j = 1; j <= n; j++) {
            if(near[j] != 0 && cost[j][near[j]] < min) {
                min = cost[j][near[j]];
                k = j;
            }
        }

        // set values to t array
        t[0][i] = k;
        t[1][i] = near[k];

        // make the near at k to 0
        near[k] = 0;

        // re-check for the new value updated is mapped to other vertices or not
        for(j = 1; j<=n; j++) {
            if(near[j] != 0 && cost[j][k] < cost[j][near[j]]) {
                near[j] = k;
            }
        }
    }

    // print the array t of minimum path
    for (i = 1; i <= n; i++) {
        cout<<" - > ( "<<t[0][i]<<", "<<t[1][i]<<" )"<<endl;
    }
    
    return 0;
}