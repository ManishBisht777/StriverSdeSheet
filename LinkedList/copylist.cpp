Node *copyRandomList(Node *head)
{
    Node *curr = head;
    Node *front = head;

    while (curr)
    {
        front = curr->next;
        Node *copy = new Node(curr->val);
        curr->next = copy;
        copy->next = front;

        curr = front;
    }

    curr = head;
    while (curr)
    {
        if (curr->random)
        {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    Node *ans = new Node(-1);
    Node *copy = ans;
    curr = head;

    while (curr)
    {
        front = curr->next->next;
        copy->next = curr->next;
        copy = copy->next;
        curr->next = front;

        curr = front;
    }

    return ans->next;
}