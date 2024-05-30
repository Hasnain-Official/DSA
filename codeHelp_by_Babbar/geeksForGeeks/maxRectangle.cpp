#include<iostream>
#include<stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
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

vector<int> prevSmallerElement(vector<int> &arr, int n) {
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

 int largestRectangleInAHistogram(vector<int> &heights) {
    int n = heights.size();
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

int maxRectangle(int* M, int n, int m) {
    vector<int> arr(m, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
        }
    }
}


int main() {
    return 0;
}