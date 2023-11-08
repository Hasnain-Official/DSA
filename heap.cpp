#include<iostream>
using namespace std;

void insert(int A[], int n) {
    int i = n;
    int temp = A[i];
    while (i > 1 && temp < A[i/2]) {
        A[i] = A[i/2];
        i = i/2;   
    }
    A[i] = temp;
}

int Delete(int A[], int n) {
    int x,i,j, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    i = 1, j = 2 * i;
    while (j < n-1) {
        if(A[j+1] > A[j]) {
            j = j + 1;
        }
        if(A[i] < A[j]) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        } else {
            break;
        }
    }
    A[n] = val;
    return val;
}



int main() {
    int H[] = {0, 10, 20, 30, 40, 50, 60, 5, 8};
    int size = 7;
    for (int i = 2; i < size; i++)
    {
        insert(H, i);
    }
    // cout<<"Deleted Value is - > "<<Delete(H, 7);
    for (int i = 7; i > 1; i++)
    {
        Delete(H, i);
    }
    

    return 0;
}