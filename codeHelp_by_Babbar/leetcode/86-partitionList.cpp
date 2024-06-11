#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ListNode {
    public : 
        int val;
        ListNode* next;
        ListNode(int data) {
            this->val = data;
            this->next = NULL;
        }
};
 
 
// partition List
/**
 * took 2 new list 
 * 1st list of lesser part
 * second list of greater equal part
*/
ListNode* partitionList(ListNode* head, int x) {
    ListNode* lessListHead = new ListNode(-1);
    ListNode* lessListTail = lessListHead;
    ListNode* greaterListHead = new ListNode(-1);
    ListNode* greaterListTail = greaterListHead;

    ListNode* temp = head;
    while(temp != NULL ) {
        cout<<temp->val<<endl;
        // ListNode* newNode = new ListNode(temp->val);
        if(temp->val < x) {
            // lessListTail->next = newNode;
            lessListTail->next = temp;
            lessListTail = lessListTail->next; 
        } else {
            // greaterListTail->next = newNode;
            greaterListTail->next = temp;
            greaterListTail = greaterListTail->next; 
        }
        temp = temp->next;
    }

    lessListTail->next = greaterListHead->next;

    return lessListHead->next;
}

int main() {
    return 0;
}