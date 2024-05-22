#include<iostream>
#include<vector>

using namespace std;

// find square root a number in O(log n)
// Linear search will give O(n)

int sqrt(int val) {
    int start = 0;
    int end = val;
    int mid = start + (end - start)/2;
    int ans = -1;
    while (start <= end) {
        long long int sq = mid * mid;
        if(sq == val) {
            return mid;
        }
        if(sq < val) {
            ans = mid;
            start = mid + 1;
        }
        if(sq > val) {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

double precision(int n, int precision, int tempRes) {
    double factor = 1;
    double ans = tempRes;
    for (int i = 0; i < precision; i++) {
        factor = factor/10;
        for (double j = ans; j*j < n; j = j + factor) {
            ans = j;
        }
    }
    return ans;
}


int main() {
    int n;
    cout<<"Enter the number to find square root : "<<endl;
    cin>>n;
    int tempRes = sqrt(n);
    cout<<"TEMP RES - "<<tempRes<<endl;
    double res = precision(n, 3, tempRes);
    cout<<"RES - "<<res<<endl;
    return 0;
}