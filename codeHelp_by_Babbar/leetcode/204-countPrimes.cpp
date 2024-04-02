#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

 bool isPrime(int n) {
    int i = 2;
    bool isPrime = true;
    if(i <= 1 || n == 2) {
        return false;
    }
    while( i < n) {
        if(n %i == 0) {
            cout<<"Not a prime number"<<endl;
            isPrime = false;
            break;
        }
        i++;
    }
    return isPrime;
}

 int countPrimes(int n) {
    
        int count = 0, i = 2;
    while(i <= n) {
        if(isPrime(i)) {
            count++;
        }
        i++;
    }
    return count;
}

// sieve of eratosthenes
int sieveCountPrimes(int n) {
     vector<bool> v(n+1, true);
    int i = 2, count = 0;
    while(i < n) {
        if(v[i]) {
            count++;
            int j = 2*i;
            while(j < n) {
                v[j] = false;
                j = j+i;
            }
        }
        i++;
    }
    return count;
}

int main() {
    // vector<int> arr;
    int n = 10;
    // arr = {6,2,8,4,10};
    int count = sieveCountPrimes(n);
    cout<<" - > "<<count;
    return 0;
}