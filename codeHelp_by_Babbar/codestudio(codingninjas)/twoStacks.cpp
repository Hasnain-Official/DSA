#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class TwoStack {
    public: 
        int* arr;
        int size;
        int top1;
        int top2;
    public: 
        TwoStack(int s) {
            this->size = s;
            arr = new int[s];
            top1 = -1;
            top2 = s;
        }

        void push1(int num) {
            if(top2 - top1 > 1) {
                top1++;
                arr[top1]= num;
            } else{
                cout<<"Stack Overflow"<<endl;
            }
        }

        void push2(int num) {
            if(top2 - top1 > 1) {
                top2--;
                arr[top2]= num;
            } else{
                cout<<"Stack Overflow"<<endl;
            }
        }

        int pop1() {
            int topElement = -1;
            if(top1 >= 0) {
                topElement = arr[top1];
                top1--;
            }
            return topElement;
        }

        int pop2() {
            int topElement = -1;
            if(top2 < size) {
                topElement = arr[top2];
                top2++;
            }
            return topElement;
        }
};

int main() {
    return 0;
}