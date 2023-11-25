#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the Number : "<<endl;
    cin>>n;
    int row = 1;
    while (row <= n) {
        int col = 1;
        while (col <= n) {
            cout<<row;
            col++;
        }
        cout<<endl;
        row++;
    }
    cout<<"----------"<<endl;
    row = 1;
    while (row <= n) {
        int col = n - row + 1;
        while (col <= n) {
            cout<<col;
            col++;
        }
        cout<<endl;
        row++;
    }
    return 0; 
}