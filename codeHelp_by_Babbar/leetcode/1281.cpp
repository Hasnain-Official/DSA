#include<iostream>
using namespace std;

int difference(int n) {
    int sum = 0, product = 1;
    while( n != 0) {
        sum += n%10;
        product *= n%10;
        n /= 10;
    }
    return product - sum;
}

int main() {
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    cout<<difference(n)<<endl;
    return 0;
}