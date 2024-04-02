#include<iostream>

using namespace std;


// correct way to solve it is with dynamic programmming, but now let it b with recursion basic
int countWaysToReachNthStairs(long long nthStair) {
    if(nthStair < 0) {
        return 0;
    }
    if(nthStair == 0) {
        return 1;
    }
    return countWaysToReachNthStairs(nthStair-1); + countWaysToReachNthStairs(nthStair-2);
}

int main() {
    // int n;
    // cin>>n;
    return 0;
}



