#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid) {
    int cowsCount = 1;
    int lastPos = -1;
    for (int i = 0; i < stalls.size() - 1; i++) {
        if((stalls[i] - lastPos) >= mid) {
            cowsCount++;
            if(cowsCount == k) {
                return true;
            } 
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggresiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < stalls.size() - 1; i++) {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi, ans = -1;
    int mid = s + (e - s)/2;
    while(s<=e) {
        if(isPossible(stalls, k, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }   
        mid = s + (e - s)/2;
    }
    return ans;
}

int main() {
    return 0;
}