#include<iostream>
using namespace std;

void operations(int a, int op, int b) {
    switch(op) {
        case '+' : cout<<a+b<<endl;
                break;
        case '-' : cout<<a-b<<endl;
                break;
        case '/' : cout<<a/b<<endl;;
                break;
        case '*' : cout<<a*b<<endl;
                break;
        default : cout<<"No Operator Entered "<<endl;
                break;
    }
}

void NoOfNotes(int n) {
    int thousand = 0, hundred = 0, fifty = 0, twenty = 0, ten = 0, one = 0;
    while(n > 0) {
        if (n/1000 != 0) {
            thousand = n/1000;
            n = n - (thousand * 1000);
        } else if(n/100 != 0) {
            hundred = n/100;
            n = n - (hundred * 100);
        } else if(n/50 != 0) {
            fifty = n/50;
            n = n - (fifty * 50);
        } else if(n/20 != 0) {
            twenty = n/20;
            n = n - (twenty * 20);
        } else if(n/10 != 0) {
            ten = n/10;
            n = n - (ten * 10);
        } else {
            one = n;
            n = 0;
        }
    }
        cout<<"Thousand - "<<thousand<<endl;
        cout<<"Hundred - "<<hundred<<endl;
        cout<<"Fifty - "<<fifty<<endl;
        cout<<"Twenty - "<<twenty<<endl;
        cout<<"One - "<<one<<endl;
}

int powerOfAB(int a, int b) {
    int res = 1;
    while(b > 0) {
        res = res * a;
        b--;
    }
    return res;
}

int main() {
    // Operands and Operation Switch case
    // int a,b;
    // char op;
    // cout<<"Enter the value of operand 1 : "<<endl;
    // cin>>a;
    // cout<<"Enter the value of operand 2 : "<<endl;
    // cin>>b;
    // cout<<"Enter the operation you want to perform : "<<endl;
    // cin>>op;
    // operations(a, op, b);

    // No. Of Notes
    // int n;
    // cout<<"Enter the Amount : "<<endl;
    // cin>>n;
    // NoOfNotes(n);
    // return 0;

    // Power of a, b
    int a,b;
    cout<<"Enter A B : "<<endl;
    cin>>a>>b;
    cout<<powerOfAB(a, b)<<endl;
}