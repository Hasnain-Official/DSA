#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter Number of rows : "<<endl;
    cin>>n;
    int row = 1;
    while (row <= n) {
        int col = n - row + 1;
        while (col <= n) {
            cout<<"*";
            col++;   
        }
        cout<<endl;
        row++;
    }
    cout<<"-------------"<<endl;
    row = 1;
    int count = 1;
     while (row <= n) {
        int col = 1;
        while (col <= n) {
            cout<<count<<" ";
            col++;   
            count++;
        }
        cout<<endl;
        row++;
    }
    cout<<"-------------"<<endl;
    row = 1;
    count = 1;
    while (row <= n) {
        int col = n - row + 1;
        while (col <= n) {
            cout<<count<<" ";
            col++;   
            count++;
        }
        cout<<endl;
        row++;
    }
    cout<<"-------------"<<endl;
    row = 1;
    while (row <= n) {
        int col = n - row + 1;
        while (col <= n) {
            cout<<row<<" ";
            col++;   
            count++;
        }
        cout<<endl;
        row++;
    }
    return 0;
}