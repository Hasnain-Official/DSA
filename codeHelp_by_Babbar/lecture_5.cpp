#include<iostream>
using namespace std;
int main() {
    // fibonacci series
    int n;
    cout<<"Enter the number for the series: "<<endl;
    cin>>n;
    int a = 0;
    int b = 1;

    int sum = 0;
    for (int i = 0; i <= n; i++) {
        /* code */
        int sum = a+b;
        cout<<sum<<endl;
        a = b;
        b = sum;
    }
    cout<<"------------------"<<endl;
    // prime or not
    int i = 2;
    bool isPrime = true;
    while( i < n) {
        if(n %i == 0) {
            cout<<"Not a prime number"<<endl;
            isPrime = false;
            break;
        }
        i++;
    }
    if(isPrime) {
        cout<<"Prime Number"<<endl;
    } else {
        cout<<"Not a Prime Number"<<endl;
    }
    cout<<"------------------"<<endl;
    return 0;
}