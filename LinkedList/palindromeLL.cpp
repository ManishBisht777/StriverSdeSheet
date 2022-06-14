bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* prev=slow ;
        slow = slow->next, prev->next = NULL;
        ListNode* temp;
        
        while(slow)
        {
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        
        fast=head;
        slow=prev;
        
        while(slow)
        {
            if(slow->val!=fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
        
        return true;
    }