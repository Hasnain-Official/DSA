#include<iostream>
#include<stack>

using namespace std;

// Time Complexity : O(n x m), Space Complexity : O(m)

vector<int> nextSmallerElement(int* arr, int n) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);
    
    // traverse the vector from n to 0.
    for(int i = n-1; i >= 0; i--) {
        int curr = arr[i];
        // pop the element from the stack so that the minimum element will be on top of stack
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        
        // push the index of the smallest element in stack
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(int* arr, int n) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i = 0; i < n; i++) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }

        // push index of the smallest element in stack
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

 int largestRectangleInAHistogram(int* heights, int n) {
    // int n = heights.size();
    vector<int> next(n);

    // find the next smallest 
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);

    // find the previous smallest
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;

    // traverse the vector for the minimum area calculation.
    for(int i = 0; i < n; i++) {

        // variable length will be the length of the rectangle.
        int length = heights[i];
        // in case the index have -1 for no minimum value on right side so set the value max of the height vector, that's why n is set to the index where no value found -1.
        if(next[i] == -1) {
            next[i] = n;
        }

        // this specific line was not in the video.
        // if(prev[i] == -1) prev[i] = -1;     

        // calculate the breadth from the indexes.
        int breadth = next[i] - prev[i] - 1;

        // update the max area for the result
        area = max(length * breadth, area);
    }
    return area;
}

// M is array of n x m
int maxRectangle(int M[5][10], int n, int m) {

    // // self 
    // // 1. compute area for the first row
    // int area = 0;

    // // 2. intialize an array with 0 of size n
    // int* heights = new int[m];
    // for(int i = 0; i < m; i++) {
    //     heights[i] = 0;
    // }

    // // 3. first row
    // int i = 0, j = 0;
    // while(j < m) {
    //     heights[j] = M[i][j];
    //     j++;
    // }

    // // 4. area of the first row
    // area = largestRectangleInAHistogram(heights, m)

    // // 5. starting from index 1
    // i++;
    // while(i < n) {
    //     j = 0;
    //     while(j < m) {
    //         // heights[j] += M[i][j];
    //         heights[j] = M[i][j] == 0 ? 0 : M[i][j];
    //         j++;
    //     }
    //     area = max(area, largestRectangleInAHistogram(heights, m));
    //     i++;
    // }

    // method : in video
    int area = largestRectangleInAHistogram(M[0], m);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(M[i][j] != 0) {
                M[i][j] += M[i-1][j];
            } else {
                M[i][j] = 0;
            }

            area = max(area, largestRectangleInAHistogram(M[i], m));
        }
    }
    return area;
}

/*
    0 1 1 0
    1 1 1 1
    1 1 1 1
    1 1 0 0
*/

int main() {
    return 0;
}