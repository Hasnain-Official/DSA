#include<iostream>
#include<vector>

using namespace std;

class Solution {
    private: 
        bool validChar(char ch) {
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') ) {
                return true;
            } else {
                return false;
            }
        }

        char toLowerCase(char ch) {
            if((ch >= 'a' && ch <= 'z') ) {
                return true;
            } else {
                return false;
            }
        }

        bool checkpalindrome(string str) {
        int s = 0, e = str.length()-1;
            while(s<=e) {
                if(str[s] != str[e]) {
                    return false;
                } else{
                    s++;
                    e--;
                }
            }
            return true;
        }


    public :
        bool isPalindrome(string str)  {
            string temp = "";
            for (int i = 0; i < str.length(); i++) {
                if(validChar(str[i])) {
                    temp.push_back(str[i]);
                }
            }
            for (int i = 0; i < str.length(); i++) {
                temp[i] = toLowerCase(temp[i]);
            }
            return checkpalindrome(temp);
        }
};

int main() {
    return  0;
}