#include<iostream>
#include<vector>

using namespace std;

void printLikeAWave(vector<vector<int>> ar, int rows, int columns) {
    int i = 0;
    while(i < columns) {
        if(i&1) {
            int j = rows-1;
            while(j > 0) {
                cout<<" "<<ar[j][i];
                j--;
            }
        } else {
            int j = 0;
            while (j < rows-1) {
                cout<<" "<<ar[j][i];
                j++;
            }
        }
        i++;
        cout<<endl;
    }
}

int main() {
    vector<vector<int>> ar;
    printLikeAWave(ar, ar.size(), ar[0].size());
}