#include<iostream>
using namespace std;

int minElement(int arr[], int size) {
    int min = INT_MAX;
    int i = size - 1;
    while (i > 0) {
        if(arr[i] < min) {
            min = arr[i];
        }
        i--;
    }
    return min;
}

int maxElement(int arr[], int size) {
    int max = INT_MIN;
    int i = size - 1;
    while (i > 0) {
        if(arr[i] > max) {
            max = arr[i];
        }
        i--;
    }
    return max;
}

bool linearSearch(int arr[], int size, int key) {
    int i = 0;
    bool found = false;
    while(i < size - 1) {
        if(arr[i] == key) {
            found = true;
            break;
        }
        i++;
    }
    return found;
}

void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1, temp = arr[0];
    while(start <= end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = arr[start];
        start++;
        end--;
    }
}

int main() {
    // int a[10] = {0};
    // for (int i = 0; i < 10; i++) {
    //     cout<<a[i]<<" ";
    // }
    int n, key;
    cout<<"Enter the number : "<<endl;
    cin>>n>>key;
    int *b = new int[n];
    cout<<"Maximum Values is : "<<maxElement(b, n)<<endl;
    cout<<"Minimum Value is : "<<minElement(b, n)<<endl;;
    cout<<"Searching ... " <<linearSearch(b, n, key)<<endl;
    return 0;
}