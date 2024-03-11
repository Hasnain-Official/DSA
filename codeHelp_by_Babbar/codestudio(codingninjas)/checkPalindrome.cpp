#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char toLowerCase(char ch) {
    if(ch >= 'a' && ch == 'z') {
        return ch;
    } else {
        return ch - 'A' + 'a';
    }
}

bool checkpalindrome(int arr[], int n){
    int s = 0, e = n-1;
    while(s<=e) {
        if(toLowerCase( arr[s] ) != toLowerCase( arr[e] )) {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

void reverse2(char str[], int size) {
    int s = 0, e = size - 1;
    while (s <= e) {
        swap(str[s++], str[e--]);
    }
}

int main() {
    char arr[20];
    cout<<"Enter the String"<<endl;
    cin>>arr;
    reverse2(arr, 20);
    
    return 0;
}