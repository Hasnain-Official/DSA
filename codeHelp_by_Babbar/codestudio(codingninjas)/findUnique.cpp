#include<iostream>
using namespace std;

// int findUnique(int arr[], int size) {
//     int i = 0;
//     int unique = arr[i];
//     while(i < size) {
//         int j = 0, count = 0;
//         while(j < size) {
//             if(arr[i] == arr[j]) {
//                 count++;
//             }
//             j++;
//         }
//         if(count == 1) {
//             cout<<"Unique - "<<arr[i]<<endl;
//         }
//         i++;
//     }
//     return 0;
// }

int findUnique(int a[], int size) {
    int ans = 0, i = 0;
    while(i < size) {
        ans = ans^a[i];
        i++;
    }
    return ans;
}

void printArray(int arr[], int size) {
    int i = 0;
    while(i < size) {
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl;
}

int main() {
    int n;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;
    int *b = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>b[i];
    }
    printArray(b, n);
    cout<<findUnique(b, n)<<endl;
    return 0;
}