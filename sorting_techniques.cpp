#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int temp = 0;
    cout<<" x - > "<<*x<<" y - > "<<*y<<endl;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int A[], int n) {
     for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            if(A[i] > A[j]) {
               swap(&A[i], &A[j]);
            }
        }
     }
}

void insertion_sort(int A[], int n) {
      for(int i = 1; i < n; i++) {
        int x = A[i];
        int j = i-1;
        while (j > -1 && A[j] > x) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
      }
}

void selection_sort(int A[], int n) {
    int j = 0, min_index = 0;
     for(int i = 0;i<n-1;i++) {
        j = i+1;
        min_index = i;
        while (j < n) {
            if(A[j] < A[min_index]) {
                min_index = j;
            }
            j++;   
        }
        swap(A[i], A[min_index]);
     }
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;
    do {
        do
        {
             i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        
        if(i<j) swap(&A[i], &A[j]);
    } while(i < j);
    swap(&A[l], &A[j]);
    return j;
}

void quick_sort(int A[], int l, int h) {
    int j;
    if(l<h) {
        j = partition(A, l, h);
        quick_sort(A, l, j);
        quick_sort(A, j+1, h);
    }
}

void merge(int A[], int B[], int m, int n, int *C) {
    int i=0, j=0, k = 0;
    while(i<m && j<n) {
        if(A[i]<B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
     while (i < m) {
        C[k++] = A[i++];
    }
    while (j < n) {
        C[k++] = B[j++];
    } 
}

void two_array_in_single_array_merge(int A[], int l, int mid, int h) {
    int i=l, j=mid+1, k = l;
    int *B = new int[h+1];
    while(i<mid && j<h) {
        if(A[i]<A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
     while (i < mid) {
        B[k++] = A[i++];
    }
    while (j < h) {
        B[k++] = A[j++];
    } 
    for (int v = l; v < h; v++) {
        A[i] = B[i];
    }
}

void merge_sort(int A[], int n) {
    int p,i, l, mid, h;
    for(p =2; p<=n;p++) {
        for (i = 0; p+i - 1 <=n; i=i+p) {
            l = i;
            h = i + p -1;
            mid = (l + h)/2;
            two_array_in_single_array_merge(A, l, mid, h);
        }
    }
    if(p/2 < n) {
        two_array_in_single_array_merge(A, 0,p/2-1, n-1);
    }
}

void recursive_merge_sort(int A[], int l, int h) {
    if(l<h) {
        int mid = (l + h)/2;
        recursive_merge_sort(A, l, mid);
        recursive_merge_sort(A, mid+1, h);
        two_array_in_single_array_merge(A, l, mid, h);
    }
}

int find_max(int A[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

void counting_sort(int A[],int n) {
    int max = find_max(A,n);
    int* B = new int[max+1];
    for (int i = 0; i < n; i++) {
        B[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        B[A[i]]++;
    }
    int i = 0 ,j = 0;
    while (i < max+1) {
        if(B[i] > 0) {
           A[j++] = i;
           B[i]--;
        } else {
            i++;
        }
    }
}

void radix_sort(int A[], int n) {

}

void shell_sort(int A[], int n) {
    int gap, i ,j, temp;
    for (gap = n/2; gap > 1; gap = gap/2) {
         for ( i = gap; i < n; i++)
         {
            temp = A[i];
            j = gap - i;
            while (j > 0 && A[j] > temp) {
                A[j+gap] = A[j];
                j = j-gap;
            }
            A[j+gap] = temp;
         }    
    }
}

int main() {
    int A[] = {2, 3, 4, 7 , 10};
    int n = 5;
    int m = 7;
    int B[] = {7, 9, 11, 13, 24, 33, 35};
    int* C = new int[n+m];
    // bubble_sort(A, n);
    // insertion_sort(A,n);
    // selection_sort(A, n);
    // quick_sort(A, 0, n);
    merge(A, B, n, m, C);
    for (int i = 0; i < n+m; i++)
    {
        cout<<"- > "<<i<<" "<<C[i]<<endl;
    }
    return 0;
}