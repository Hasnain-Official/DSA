#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ["s","k","y", " ","i","s"] - > ["i","s"," ","s","k","y"]
// reverse the whole array then reverse the words



void reverseArray(vector<char> &arr, int s, int e) {
    while(s <= e) {
        swap(arr[s++], arr[e--]);
    }
}

void reverseWordsString(vector<char> &arr, int n) {
    reverseArray(arr, 0 ,n-1);
     
    int i = 0, s = 0;
    while(i < n) {
        if(arr[i] == ' ') {
            reverseArray(arr, s, i-1);
            s = i + 1;
        }
        i++;
    }
    reverseArray(arr, s, n - 1);
}

int main() {
    vector<char> ch = {'s', 'k', 'y', ' ', 'i', 's'};
    reverseWordsString(ch, 6);
    cout << "Reversed string: ";
    for (char c : ch) {
        cout << c;
    }
    cout << endl;   
    return 0;
}