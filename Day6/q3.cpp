/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        ListNode* t1=headA;
//        ListNode* t2= headB;
//        while(t1!=t2){
//            if(t1==NULL)
//             t1=headA;
//            else if(t2==NULL)
//             t2=headB;
//            else{
//                t1=t1->next;
//                t2=t2->next;
//            }
           
//        } 
//         return t1;
//         unordered_set<ListNode*>s;
//         while(headA!=NULL){
//             s.insert(headA);
//             headA=headA->next;
//         }
        
//         while(headB){
//             if(s.find(headB)!=s.end())
//                 return headB;
//             headB=headB->next;
//         }
//         return NULL;
        
        
        // stack 
        
        ListNode* first = headA;
        stack<ListNode*>a;
        stack<ListNode*>b;
        while(first){
            a.push(first);
            first=first->next;
        }
        first=headB;
        while(first){
            b.push(first);
            first=first->next;
        }
        
         while(a.top()==b.top()){
            first = a.top();
             a.pop();
             b.pop();
             
            if(a.empty()|| b.empty())
                break;
        }
        return first;
    }
    
};
// intersection of two linked lists
