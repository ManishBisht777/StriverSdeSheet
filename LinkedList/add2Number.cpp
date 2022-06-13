ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *ans = new ListNode(-1);
    ListNode *curr = ans;

    int carry = 0;

    while (carry || l1 || l2)
    {
        int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry = sum / 10;
        sum = sum % 10;

        curr->next = new ListNode(sum);

        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
        curr = curr->next;
    }

    return ans->next;
}