#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

void printArray(int arr[], int size) {
    int i = 0;
    while(i < size) {
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl;
}

bool noOfOccurence(int arr[], int size) {
    unordered_map<int,int> obj;
    set<int> s;
    int i = 0;
    while(i < size) {
        obj[arr[i]] = obj[arr[i]] ? obj[arr[i]] + 1 : 1 ;
        i++;
    }
    int *occ = new int[obj.size()];
    i = 0;
    for(auto it:obj) {
        occ[i]=it.second;
        s.insert(it.second);
        i++;
    }
    return obj.size() == s.size();
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
    cout<<noOfOccurence(b, n)<<endl;
    return 0;
}