#include<iostream>
#include<vector>

using namespace std;

int fact(int n) {
    if(n <= 1) {
        return 1;
    }
    return n * fact(n-1);
}

void reachHome(int src, int dest) {
    if(src == dest) {
        cout<<"Reached"<<endl;
        return ;
    }
    src++;
    cout<<"step - > "<<src<<endl;
    reachHome(src, dest);
}

int main() {
    // int n ;
    // cin>>n;
    // cout<<fact(n)<<endl;
    reachHome(0, 15);
    return 0;
}