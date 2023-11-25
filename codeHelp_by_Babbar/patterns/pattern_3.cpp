#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter Number of rows : "<<endl;
    cin>>n;
    int row = 1;
    while (row <= n) {
        int value = row;
        int col = 1;
        while (col <= row) {
           cout<<value<<" ";
           value++;
            col++;   
        }
        cout<<endl;
        row++;
    }
    cout<<"-------------"<<endl;
    return 0;
}