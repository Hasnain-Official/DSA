#include<iostream>
using namespace std;

int countOnes(int n) {
    int count = 0;
    while(n != 0) {
        if(n&1) {
            count++;
        }
        n = n>>1;
    }
    return count;
}

// count no. of 1s in binary 
int main() {
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    cout<<"Number of One's : "<<countOnes(n)<<endl;
    return 0;
}