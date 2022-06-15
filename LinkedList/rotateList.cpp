ListNode *rotateRight(ListNode *head, int k)
{

    if (!head)
        return head;

    int len = 1;
    ListNode *tail = head;
    while (tail->next)
    {
        tail = tail->next;
        len++;
    }

    tail->next = head;
    k = k % len;

    for (int i = 0; i < len - k; i++)
    {
        tail = tail->next;
    }

    head = tail->next;
    tail->next = NULL;

    return head;
}