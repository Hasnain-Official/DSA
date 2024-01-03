#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    int i = n;
    int sum = 0;
    while(sum >= 0) {
        while(i > 0){
            sum += pow(i%10, 2);
            i /= 10;
        }
        if(sum <= 9) {
            break;
        } else {
            i = sum;
            sum = 0;
        }
    }
    bool res = (sum == 1 || sum == 7) ? true : (sum > 0 && sum < 10) ? false : true;
    cout<<sum<<" - "<<res<<endl;
    return 0;
}