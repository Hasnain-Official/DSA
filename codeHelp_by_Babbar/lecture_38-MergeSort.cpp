#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Merge Sort

void mergeArray(vector<int>& arr, int s, int e) {
    int mid = s + (e - s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int> first(len1);
    vector<int> second(len2);

    // copy values
    
    int mainIndex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainIndex++];
    }

    int k = mid+ 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainIndex++];
    }

    // merge 2 sorted Arrays
    int index1 = 0, index2 = 0;
    mainIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainIndex++] = first[index1++];
        } else {
            arr[mainIndex++] = second[index2++];
        }
    }

    // copy the remaining element
    while(index1 < len1) {
        arr[mainIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainIndex++] = second[index2++];
    }

    first.clear();
    second.clear();
    
}

void mergeSort(vector<int>& arr, int s, int e) {
    
    if(s >= e) {
        return ;
    }
    int mid = s + (e - s)/2;

    //left
    mergeSort(arr, s, mid);

    //right
    mergeSort(arr, mid+1, e);

    mergeArray(arr, s ,e);


}


void printVector(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<" - > "<<i<<" "<<arr[i]<<endl;
    }
}

int main() {
    vector<int> arr1;
    arr1 = {6,2,8,4,10};
    // arr2 = {6,2,8,4,10};
    // int pos = 3;
    mergeSort(arr1, 0, arr1.size()-1);
    printVector(arr1);
    return 0;
}