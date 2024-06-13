#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

string firstNonRepeatingCharacterInAStream(string A) {
    string ans = "";
    queue<char> q;

    for(int i = 0 ; i < A.length(); i++) {

        // check for the empty queue and queue front is equal to character
        if(!q.empty() && q.front() == A[i]) {

            // pop the element
            q.pop();

            // in case matches put a hash there
            ans += "#";
        } else {

            // push the element and concat the queue front with string
            q.push(A[i]);
            ans += q.front();
        }
    }

    return ans.length() > 0 ? ans : "#";
}

std::string firstNonRepeatingCharacterInAStreamFromVideo(std::string A) {
    std::string ans = "";
    std::queue<char> q;
    std::unordered_map<char, int> freq;

    for(int i = 0; i < A.length(); i++) {
        char currentChar = A[i];
        freq[currentChar]++;
        q.push(currentChar);

        // Remove all characters from the queue that have a frequency greater than 1
        while(!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if(q.empty()) {
            ans += "#";
        } else {
            ans += q.front();
        }
    }

    return ans;
}

int main() {
    string str = "aabbcd";
    string ans = firstNonRepeatingCharacterInAStream(str);
    cout<<" - > "<<ans;
    return 0;
}