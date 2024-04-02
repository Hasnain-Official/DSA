#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void reorderList(ListNode* head) {
        ListNode* temp = head;
        vector<int> v1;
        vector<int> res;
        if(temp->next != NULL) {
            while(temp != NULL) {
                v1.push_back(temp->val);
                temp = temp->next;
            }
            int i = 0,j = v1.size()-1;
            while(i <= j) {
                res.push_back(v1[i]);
                res.push_back(v1[j]);
                i++;
                j--;
            }
            temp = head;
            i = 0;
            while(i < res.size() && temp != NULL) {
                temp->val = res[i];
                temp = temp->next;
                i++;
            }
        }
    }

    int main() {
        return 0;
    }