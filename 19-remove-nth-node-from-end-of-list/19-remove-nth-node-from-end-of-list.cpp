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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t = head;
        int c = 0;
        while(t!=NULL){
            c++;
            t=t->next;
        }
        if(c==1&&n==1)
            return NULL;
        if(c==2){
            if(n==1){
                head->next=NULL;
                return head;
            }else if(n==2){
                head=head->next;
                return head;
            }
        }
        int k  = c - n +1;
        t = head;
        if(k==1)
            return head->next;
        
        k = k-1;
        ListNode* t1=head;
        ListNode* t2=head;
        while(k--){
            t1=t;
            t=t->next;
            
            t2=t->next;
        }
         t1->next=t2;
        return head;
        
        
    }
};