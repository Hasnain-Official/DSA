#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    int m = n;
    int mask = 0;
    while(m != 0) {
        mask = (mask<<1) | 1;
        m = m>>1;
    }
    int res = (~n)&mask;
    cout<<res<<endl;
    return 0;
}