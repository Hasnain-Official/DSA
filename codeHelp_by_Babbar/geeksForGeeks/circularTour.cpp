#include<iostream>
#include<queue>

using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

/**
 * Intuition : every time you go move based on petrol there is balance left from previous station
 * Find the difference between perol and distance = balance
 * if( bcalance < 0 ) then deficit amount or amount less will be stored in deficit , start = index at which condition fails, put start onto from that index to index+1
 * set balance = 0 
 * 
 * if deficit + balance  >= 0 then return the starting index of the trip otherwise -1 means no possible way
 * 
*/

class Solution {
    public:
        int circularTour(petrolPump P[], int n);
};

int Solution::circularTour(petrolPump P[], int n) {
    queue<int> q;
    int deficit = 0, balance, start = 0;
    // traverse to all the petrol and distance array
    for(int i = 0; i < n; i++) {

        // find the difference, if less than 0 then save the deficit amount otherwise carry on the traversing
        balance = P[i].petrol - P[i].distance;
        if(balance < 0) {
            deficit+= balance;
            start = i + 1;
            balance = 0;
        }
    }

    // check for the deficit + balance to get the starting index of the possible outcome otherwise in case of no possible outcome reutrn -1
    return (deficit + balance >= 0) ? start : -1;
};

int main() {
    Solution *s = new Solution();
    return 0;
}