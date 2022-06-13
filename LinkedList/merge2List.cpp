ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *list = new ListNode(-1);
    ListNode *curr = list;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            curr->next = new ListNode(list1->val);
            list1 = list1->next;
            curr = curr->next;
        }
        else
        {
            curr->next = new ListNode(list2->val);
            list2 = list2->next;
            curr = curr->next;
        }
    }

    while (list1)
    {
        curr->next = new ListNode(list1->val);
        curr = curr->next;
        list1 = list1->next;
    }

    while (list2)
    {
        curr->next = new ListNode(list2->val);
        curr = curr->next;
        list2 = list2->next;
    }

    return list->next;
}