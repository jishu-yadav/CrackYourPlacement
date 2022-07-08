/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans =0;
        int c=0;
        ListNode* temp = head;
        while(temp){
            c++;
            temp=temp->next;
        }
        int i = c-1;
        while(head){
            ans+=pow(2,i--)*(head->val); 
            head = head->next;
        }
        return ans;
    }
};