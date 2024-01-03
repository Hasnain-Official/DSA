#include<iostream>
using namespace std;

int main() {
    int row = 1;
    int n;
    cout<<"Enter the number of rows :"<<endl;
    cin>>n;
    while(row <= n) {
        int col = 1;
        char ch = 'A' + row - 1;
        while(col <= n) {
            cout<<ch;
            col++;
        }
        cout<<endl;
        row++;
    }
    cout<<"-------------------"<<endl;
    row = 1;
     while(row <= n) {
        int col = 1;
        while(col <= n) {
            char ch = 'A' + col - 1;
            cout<<ch;
            col++;
        }
        cout<<endl;
        row++;
    }
    cout<<"-------------------"<<endl;
    row = 1;
     while(row <= n) {
        int col = 1;
        char ch = 'A' + row - 1;
        while(col <= row) {
            cout<<ch;
            col++;
        }
        cout<<endl;
        row++;
    }
    cout<<"-------------------"<<endl;
    row = 1;
     while(row <= n) {
        int col = 1;
        char ch = 'A' + row - 1;
        while(col <= row) {
            cout<<ch<<" ";
            ch = ch + 1;
            col++;
        }
        cout<<endl;
        row++;
    }
     cout<<"-------------------"<<endl;
    row = 1;
     while(row <= n) {
        int col = 1;
        char ch = 'A' + n - row;
        while(col <= row) {
            cout<<ch<<" ";
            ch = ch + 1;
            col++;
        }
        cout<<endl;
        row++;
    }
    return 0;
}