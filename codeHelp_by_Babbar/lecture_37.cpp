#include<iostream>

using namespace std;

// void reverseString(string& str, int i, int j) {
//     if(i > j) {
//         return ;
//     }
//     swap(str[i], str[j]);
//     i++;
//     j--;
//     reverseString(str, i, j);
// }

void reverseString2(string& str, int i) {
    if(i > str.length()-i-1 ) {
        return ;
    }
    swap(str[i], str[str.length()-i-1]);
    i++;
    reverseString2(str, i);
}

// check palindrome string
bool checkPalin(string& str, int i, int j) {
    if(i > j) {
        return true;
    }
    if(str[i] != str[j]) {
        return false;
    } 
    i++;
    j--;
    return checkPalin(str, i, j);
}


int ABpower(int a, int b) {
    if( b == 0 ) {
        return 1;
    }
    if(b == 1) {
        return a;
    }
    // return a * ABpower(a, b-1);
    int ans = ABpower(a, b/2);
    if(b%2 == 0) {
        return ans * ans;
    } else {
        return a * ans * ans;
    }
}

// bubble sort using recursion
void bubbleSort(int arr[], int size) { 
    if(size == 0 || size == 1) {
        return ;
    }
    for(int i = 0; i < size; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSort(arr, size-1);
}

int main() {
    // int arr[] = {6,2,8,4,10};
    int arr[] = {2,4,6,8,10};
    string s = "abbad";
    // reverseString2(s, 0);
    // cout<<checkPalin(s, 0, s.length() - 1)<<endl;

    // power
    cout<<ABpower(2,5)<<endl;
    return 0;
}