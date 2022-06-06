int getlen(Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }

    return len;
}

int findIntersection(Node *head1, Node *head2)
{
    if (!head1 || !head2)
        return -1;
    // Write your code here
    int d1 = getlen(head1);
    int d2 = getlen(head2);

    int d = abs(d1 - d2);

    if (d2 > d1)
        while (d--)
            head2 = head2->next;
    else
        while (d--)
            head1 = head1->next;

    while (head1 && head2)
    {
        if (head1 == head2)
            return head2->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}