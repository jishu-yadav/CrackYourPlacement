class Solution {
public:
    bool isPalindrome(ListNode* head) {
          ListNode* fast = head;
       ListNode* slow = head;
       while(fast != NULL && fast -> next != NULL){
           slow = slow->next;
           fast = fast -> next -> next;
       }
       
       //reversing last half linked list
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != slow)
        {
           ListNode* temp = curr->next;
           curr->next = prev;
           prev = curr;
           curr = temp;  
        }
       //for odd LL
       if(fast)
           slow = slow->next;
       
       while(slow!=NULL && prev != NULL){
           if(slow -> val != prev->val)
               return false;
           slow = slow->next;
           prev = prev->next;
       }
       return true;
    }
};
