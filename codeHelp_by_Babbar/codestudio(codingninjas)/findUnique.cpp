#include<iostream>
using namespace std;

int findUnique(int arr[], int size) {
    int i = 0;
    while(i < size) {
        
        i++;
    }
    return 0;
}

void printArray(int arr[], int size) {
    int i = 0;
    while(i < size) {
        cout<<arr[i]<<" ";
        i++;
    }
}

int main() {
    int n;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;
    int *b = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>b[i];
    }
    cout<<findUnique(b, n)<<endl;
    printArray(b, n);
    return 0;
}