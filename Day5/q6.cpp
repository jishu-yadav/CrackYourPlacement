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
   
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        
        while(l1!=NULL|| l2!=NULL || carry){
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
             if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry  = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
            
        }
        return dummy->next;
        
        
        // look into below code again it was having some error
//         ListNode* result = new ListNode();
//         ListNode* tl1=l1;
//         ListNode* tl2=l2;
//         ListNode* p = result;
//         //p->next = result;
//         int n1=0,n2=0;
//         while(tl1!=NULL){
//             n1++;
//             tl1=tl1->next;    
//         }
//          while(tl2!=NULL){
//             n2++;
//             tl2=tl2->next;
//         }
        
//         int rem=0,car=0,s=0;
//         if(n1<n2){
//             while(n1--){
//                 s = car + l1->val+l2->val;
//                 rem = s%10;
//                 car = s/10;
//                 ListNode* tmp = new ListNode(rem);
//                 p->next = tmp;
//                 p=p->next;
//             }
//         }else{
//             while(n2--){
//                 s = car + l1->val+l2->val;
//                 rem = s%10;
//                 car = s/10;
//                 ListNode* tmp = new ListNode(rem);
//                 p = p->next;
//             }
//         }
//         while(n1--){
//                 s = car + l1->val;
//                 rem = s%10;
//                 car = s/10;
//                 ListNode* tmp = new ListNode(rem);
//                 p = p->next;
                
//         }
//          while(n2--){
//                 s = car + l2->val;
//                 rem = s%10;
//                 car = s/10;
//                 ListNode* tmp = new ListNode(rem);
//                 p = p->next;
//         }
//         return result->next;
        
    }
};
// add two numbers
