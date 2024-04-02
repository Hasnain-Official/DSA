#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Quick Sort

// int partition(vector<int>& arr, int s, int e) {
//     int pivot = arr[s];
//     int i = s, j = e;

//     while(i < j) {
//         while(arr[i] <= pivot && i < j) {
//             i++;
//         }
//         while(arr[j] > pivot) {
//             j--;
//         }
//         if (i < j) {
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[s], arr[j]);
//     return j;
// }

int partition(vector<int>& arr, int s, int e) {
    int pivot = arr[s], count = 0;
    int i = s;
    // count minimum elements than pivot
    while(i < e) {
        if(arr[i] <= pivot) {
            count++;
        }
        i++;
    }

    // swao the pivot to it respective position
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    i = s;
    int j = e;
    while(i < pivotIndex && j > pivotIndex) {
        if(arr[i] < pivot) {
            i++;
        }        
        if(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(vector<int>& arr, int s, int e) {
    
    if(s >= e) {
        return ;
    }
    
    int pivot = partition(arr, s, e);

    // left 
    quickSort(arr, s, pivot-1);
    quickSort(arr, pivot+1, e);

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
    quickSort(arr1, 0, arr1.size()-1);
    printVector(arr1);
    return 0;
}