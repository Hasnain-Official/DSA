#include<iostream>
#include <math.h>

using namespace std;

int convertDecimalToBinary(int n) {
     int ans = 0, i = 0;
    while(n != 0) {
        int bit = n&1;
        ans = (bit * pow(10, i)) + ans;

        n = n>>1;
        i++;
    }
    return ans;
}

string decimalToBinaryNegativeNumber(int n) {
    n = abs(n);
    string str = "";
    while (n != 0) {
        str = (n&1 ? '0' : '1') + str;
        n = n>>1;
    }
    int i = str.length() - 1;
    cout<<"One's Compliment - "<<str<<endl;
    string twosStr = str;
    while (i > 0) {
        if(str.at(i) == '1') {
            twosStr[i] = '0';
        } else {
            twosStr[i] = '1';
            break;
        }
        i--;
    }
    return twosStr;
}

// int binaryToDecimal(string n) {
//     int i = 0, digit = 0;
//     int j = n.length() - 1;
//     while(i < n.length() && j >= 0) {
//         cout<<i<<endl;
//         digit += ((n.at(j) == '1' ? 1 : 0) * pow(2, i));
//         i++;
//         j--;
//     }
//     return digit;
// }


int binaryToDecimal(int n) {
    int i = 0, digit = 0;
    while(n > 0) {
        if(n%10) {
            digit += (n%10 * pow(2, i));
        }
        i++;
        n = n/10;
    }
    return digit;
}

int main() {
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    // cout<<convertDecimalToBinary(n)<<endl;
    // cout<<"----------------"<<endl;
    // cout<<decimalToBinaryNegativeNumber(n)<<endl;
    cout<<"----------------"<<endl;
    // string n;
    // cout<<"Enter the binary number : "<<endl;
    // cin>>n;
    cout<<binaryToDecimal(n)<<endl;
    return 0;
}