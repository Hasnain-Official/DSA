#include<iostream>
#include<deque>
#include<vector>
using namespace std;


/**
 * Intiution : use data structure accordingly, here using DEQueue
*/
vector<long long> firstNegativeNumberIntergerInEveryWindowOfSizeK(long long A[], long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> v;

    // process first window
    for(int i = 0; i < K; i++) {
        if(A[i] < 0) {
            dq.push_back(i);
        }
    }

    // find first -ve number in the window
    if(!dq.empty()) {
        int ele = dq.front();
        v.push_back(ele);
        dq.pop_front();
    } else {
        v.push_back(0);
    }

    // process remaining elements
    for(int i = K; i < N; i++) {

        // removal
        if(!dq.empty() && i - dq.front() >= K) {
            dq.pop_front();
        }

        // if 
        if(A[i] < 0) {
            dq.push_back(i);
        }

        if(!dq.empty()) {
            int ele = dq.front();
            v.push_back(ele);
            dq.pop_front();
        } else {
            v.push_back(0);
        }
    }
    return v;
}

int main() {
    
    // firstNegativeNumberIntergerInEveryWindowOfSizeK();

    
}