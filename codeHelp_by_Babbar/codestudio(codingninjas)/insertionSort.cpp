#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<" - > "<<i<<" "<<arr[i]<<endl;
    }
}

void insertionSort(vector<int> arr) {
    for (int i = 1; i < arr.size(); i++) {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = temp;
    }
    printVector(arr);
}

void insertionSort2(vector<int> arr) {
    int i = 1;
    while (i < arr.size()) {
        int temp = arr[i], j = i-1;
        while (j >= 0) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
            j--;
        }
        arr[j+1] = temp;
        i++;
    }
    printVector(arr);
}

// Adaptable : as it starts sorting it seems easy
// stable : each element is at same order of position in case of dulicacy
// insertion sort is stable and adaptable
/**
 n - small - good performance
 n - partially sorted - better performance
 Best Case - O(n)
 Worst Case - O(n2)
 Time Complexity - O(n2)
*/

int main() {
    vector<int> arr;
    arr = {6,2,8,4,10};
    insertionSort2(arr);
    return 0;
}