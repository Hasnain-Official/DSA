#include<iostream>
#include<vector>

using namespace std;

void reverse(char arr[], int size) {
    int s = 0, e = size - 1;
    while(s <= e) {
        swap(arr[s++], arr[e--]);
    }
}

int main() {
    char name[20];
    cout<<"Enter Name : "<<endl;
    cin>>name;

    cout<<"Your name is : "<<name<<endl;

    int i = 0, count = 0;
    while(name[i] != '\0') {
        count++;
        i++;
    }
    cout<<"Length of string  : "<<count<<endl;
    reverse(name, count);
    cout<<"Your name is : "<<name<<endl;

    return 0;
}


