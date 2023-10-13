// // using array

// #include<iostream>

using namespace std;

// struct stack {
//     int size;
//     int top;
//     int *s;
// } s;

// void create_stack(stack *st) {
//     cout<<"Enter the Size of Stack - "<<endl;
//     cin>>st->size;
//     st->top = -1;
//     st->s = new int[st->size];
// }

// void Display(stack *st) {
//     for(int i = st->top; i >= 0; i--) {
//         cout<<" - > "<<st->s[i]<<endl;
//     }
//     cout<<" Stack Ended - > "<<endl;
// }

// void push(stack *st, int x) {
//     if(st->top == st->size - 1) {
//         cout<<"Stack Overflow"<<endl;
//     } else {
//         st->s[++st->top] = x;
//     }
// }


// int pop(stack *st) {
//     int x = -1;
//     if(st->top == -1) {
//         cout<<"Stack Underflow"<<endl;
//     } else {
//         x = st->s[st->top--];
//     }
//     return x;
// }

// int is_balance(stack *s,char *exp) {
//     int i;
//     for(i = 0; exp[i] != '\0'; i++) {
//         if(exp[i] == '(') {
//             push(s, exp[i]);
//         } else if(exp[i] == ')') {
//             if(s->top == -1) {
//                 return 0;
//             }
//             pop(s);
//         }
//     }
//     if(s->top == -1) {
//         return 1;
//     } else {
//         return 0;
//     }
// }




#include<iostream>
#include<stack>


class Solution {
public:
    // bool isValid(string s) {
    //     stack<int> st;
    //     // cout<<st.top()<<endl;
    //     int i;
    //     for(i = 0; s[i] != '\0'; i++) {
    //         // cout<<s[i]<<" "<<st.top()<<endl;
    //         if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
    //             st.push(s[i]);
    //         } else if(s[i] == ')' || s[i] == '}'|| s[i] == ']') {
    //             if(st.top() == -1) {
    //                 return false;
    //             }
    //             st.pop();   
    //         }
    //     }
    //     // cout<<st.top()<<endl;
    //     if(st.empty()) {
    //         return 1;
    //     } else {
    //         return 0;
    //     }
    // }

    bool isValid(string s) {
        stack<int> st;
        int i;
        for(i = 0; s[i] != '\0'; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(!st.empty()) { 
                    if((st.top() == '(' && s[i] == ')') || 
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']')
                    ) {
                        st.pop();
                    } else {    
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if(st.empty()) {
            return 1;
        } else {
            return 0;
        }
    }
};


int main() {
    cout<<"Stack using Array"<<endl;
    // create_stack(&s);

    // char a[] = "(){}[]";
    char a[] = "(](){)";
    // cout<<is_balance(&s, a)<<endl;
    Solution sol;
    cout<<sol.isValid(a)<<endl;
    // push(&s, 10);
    // push(&s, 30);
    // // push(&s, 40);
    // // push(&s, 50);
    // Display(&s);
    // pop(&s);
    // pop(&s);
    // pop(&s);
    // Display(&s);
    
    return 0;
}




