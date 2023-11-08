#include<iostream>
// #define SIZE 10;
const int SIZE = 10;
using namespace std;


int hash_key(int key) {
    return key%SIZE;
}

int probe(int H[], int key) {
    int index = hash_key(key);
    int i = 0;
    while (H[(index+i) % SIZE] != 0) {
        i++;
    }
    
    return (index+i)%SIZE;
}

void insert(int H[], int key) {
    int index = hash_key(key);
    if(H[index] != 0) {
        index = probe(H, key);
    }
    H[index] = key;
}

int search(int H[], int key) {
    int index = hash_key(key);
    int i = 0;
     while (H[(index + i) % SIZE] != 0) {
        i++;
    }
    return (index+i)%SIZE;
}

int main() {
    int H[] = {0};
    return 0;
}