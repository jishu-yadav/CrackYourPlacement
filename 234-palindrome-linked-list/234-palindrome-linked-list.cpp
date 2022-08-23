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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* next = NULL;
        ListNode* cur= head;
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
        
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast= head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast)
           slow = slow->next;
        
        fast = slow;
        slow=head;
        fast = reverse(fast);
        //cout<<slow->val <<" "<<fast->val<<" ";
        
        while(slow!=NULL &&fast!=NULL){
            if(slow->val!=fast->val){
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};