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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        ListNode* list1=h1;
        ListNode* list2=h2;
        ListNode* list=new ListNode(NULL);
        ListNode* dummy = list;
        while(list1&&list2){
            if(list1->val <= list2->val){
                list->next = new ListNode(list1->val);
                list1=list1->next;
                list = list->next;
            }else{
                list->next = new ListNode(list2->val);
                list2=list2->next;
                list = list->next;
            }
            
        }
            
        while(list1){
            list->next = new ListNode(list1->val);
            list1=list1->next;
            list=list->next;
        }
           while(list2){
            list->next = new ListNode(list2->val);  
            list2=list2->next;
               list=list->next;
               
        }
        
        return dummy->next;
    }
};
// merge two sorted linkedlist
