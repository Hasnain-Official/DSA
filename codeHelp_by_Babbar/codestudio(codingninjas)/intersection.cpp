#include<iostream>
using namespace std;

void intersection(int arr[], int aSize, int brr[], int bSize) {
    int maxsize = (aSize > bSize) ? aSize : bSize;
    int *ans = new int[maxsize];
    int i = 0, j = 0;
    int indexI = 0;
    while(i < aSize && j < bSize) {
        if(arr[i] > brr[j]) {
            i++;
        } else if(arr[i] == brr[j]) {
            ans[indexI] = arr[i];
            indexI++;
            i++;
            j++;
            cout<<" - > "<<arr[i]<<endl;
        } else {
            j++;
        }
    }
}

int main() {
    return 0;
}