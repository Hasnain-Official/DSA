#include<iostream>
#include<cmath>
using namespace std;

bool isPowerOfTwo(int n) {
    int m =n;
    int i = 0;
    bool isPower = false;
    if(n <= 1 || n > INT_MAX || n < INT_MIN) {
     return isPower;   
    }
    while(i <= (n/2)) {
        if(pow(2,i) == n) {
            isPower = true;
            break;
        }
        i++;
    }
    return isPower;
}

int main() {
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    cout<<isPowerOfTwo(n)<<endl;
    return 0;
}