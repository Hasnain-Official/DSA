#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of rows: "<<endl;
    cin>>n;
    int row = 1;
     while(row <= n) {
        int space = n - row;
        while(space) {
            cout<<" ";
            space--;
        }
        int col = 1;
        while(col <= row) {
            cout<<"*";
            col++;
        }
        cout<<endl;
        row++;
    }
    cout<<"----------------"<<endl;
    row = 1;
    while(row<=n) {
        int col = n - row + 1;
        while(col > 0) {
            cout<<"*";
            col--;
        }
        cout<<endl;
        row++;
    }
    cout<<"----------------"<<endl;
    row = 1;
    while(row <= n) {
        int space = row - 1;
        while(space) {
            cout<<" ";
            space--;
        }
        int col = n - row + 1;
        while(col > 0) {
            cout<<"*";
            col--;
        }
        cout<<" "<<endl;
        row++;
    }
    cout<<"----------------"<<endl;
    row = 1;
    while(row <= n) {
        int space = n - row;
        while(space){
            cout<<" ";
            space--;
        }
        int col = 1;
        while(col <= row) {
            cout<<col;
            col++;
        }

        col = row - 1;
        while(col > 0) {
            cout<<col;
            col--;
        }
        cout<<endl;
        row++;
    }
    cout<<"----------------"<<endl;
    /*
            1234554321
            1234**4321
            123****321
            12******21
            1********1
    */
    row = 1;
    while(row <= n) {
        int col = 1;
        while(col <= n - row + 1) {
            cout<<col;
            col++;   
        }
        col = 1;
        while(col<= row - 1) {
            cout<<"*";
            col++;
        }
        col = 1;
        while(col<= row - 1) {
            cout<<"*";
            col++;
        }
        col = n - row + 1;
        while(col > 0) {
            cout<<col;
            col--;   
        }
        cout<<endl;
        row++;
    }
    return 0;
}


// Homework
/*
    1111
     222
      33
       4

    1234
     234
      34
       4

       1
      22
     333
    4444
*/