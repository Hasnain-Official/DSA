// duplicate appears once  or twice

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

void findAllDuplicates(int a[], int size) {
    unordered_map<int,int> obj;
    int i = 0;
    while (i < size) {
        obj[a[i]] = obj[a[i]] ? obj[a[i]] + 1 : 1;
    }
    for(auto it:obj) {
        if(it.second > 1) {
            cout<<" - > "<<it.first<<endl;
        }
    }
}

int main() {
    // cout<<findAllDuplicates()<<endl;
    return 0;
}