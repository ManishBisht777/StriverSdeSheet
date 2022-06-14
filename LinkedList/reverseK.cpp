ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k == 1)
        return head;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *curr = dummy, *nxt, *prev = dummy;

    int len = 0;

    while (curr = curr->next)
        len++;

    while (len >= k)
    {
        curr = prev->next;
        nxt = curr->next;

        for (int i = 1; i < k; i++)
        {
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
            nxt = curr->next;
        }

        prev = curr;
        len -= k;
    }

    return dummy->next;
}