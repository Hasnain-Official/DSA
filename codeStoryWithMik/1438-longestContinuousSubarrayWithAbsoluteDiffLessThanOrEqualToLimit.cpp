// 1438-longestContinuousSubarrayWithAbsoluteDiffLessThanOrEqualToLimit
// Company - Uber
// Subarray 

#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

// Intuition : 
/**
 * Contiguous Sub array suggests to use sliding window
 * in order to get the min and max value, for that use heap
 * variable to store the result, i , j
 * start the window at 0 index i,j
 * move j if arr[i] + arr[j] <= limit, insert the element with index into max heap and min heap;
 * compare the previous resultant and difference of i and j index, assign the max value to result variable.
 * move i to min element + 1 index in case of arr[i] + arr[j] > limit, before poping check for the minimum index of element in both heaps
 * return the result.
 */


// Time Complexity - O(n logn), Space Complexity - O(n + n)
class Solution {

    // aliases for pair
    using p = pair<int, int>;
    // or
    typedef pair<int, int> P;
    public:
        int longestSubarray(vector<int>& nums, int limit) {
                int n = nums.size(), maxLength = 0;
                priority_queue<P, vector<P>> maxpq; // max-heap
                priority_queue<P, vector<P>, greater<P>> minpq; // min-heap
                // sliding window initial indexes
                int i = 0, j = 0;

                // i and j are traversing element once
                while(i <= j && j < n) {  // O( (n + n) * log n) -> O(nlogn)

                    // push elements into heap to get the minimum and maximum of sub array into pair of element, index
                    maxpq.push({nums[j], j});
                    minpq.push({nums[j], j});

                    // difference of element is greater than limit or not
                    while(maxpq.top().first - minpq.top().first > limit) {

                        // move i to the next index of smallest element
                        i = min(maxpq.top().second, minpq.top().second) + 1;

                        // pop the index less than i from max heap
                        while(maxpq.top().second < i) {
                            maxpq.pop(); // O(log n)
                        }

                        // pop the element less than i from min heap
                        while(minpq.top().second < i) {
                            minpq.pop(); // O(log n)
                        }
                    }
                    // compare and assign the maximum value to maxLength
                    maxLength = max(maxLength, j-i+1);
                    j++;
                }
                return maxLength;
        }

        // using MultiSet
        // Same complexity
        int longestSubarrayUsingMultiset(vector<int>& nums, int limit) {
            int n = nums.size();
            int i = 0, j = 0, maxLength = 0;

            multiset<int> mset;

            while(j < n) {

                // insert the element in set
                mset.insert(nums[j]);

                // check for the last(max element) and first(min element) difference with limit
                while (*mset.rbegin() - *mset.begin() > limit) {
                    // erase the element as it is above the limit given
                    mset.erase(mset.find(nums[i])); 
                    i++;
                }

                maxLength = max(maxLength, j - i + 1);
                j++;
            }

            return maxLength;
        }
};

int main() {
    return 0;
}