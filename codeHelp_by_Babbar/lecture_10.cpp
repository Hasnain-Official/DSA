#include<iostream>
using namespace std;

void reverseAlternate(int arr[], int size) {
    int i = 0, j = 1;
    while(i < size && j < size) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i += 2;
        j += 2;
    }
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
    reverseAlternate(b, n);
    printArray(b, n);
    return 0;
}