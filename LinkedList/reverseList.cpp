ListNode *reverseList(ListNode *head)
{

    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nxt;

    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}