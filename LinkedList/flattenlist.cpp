Node *merge(Node *l1, Node *l2)
{
    Node *temp = new Node(-1);
    Node *curr = temp;

    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            curr->bottom = l1;
            l1 = l1->bottom;
            curr = curr->bottom;
        }
        else
        {
            curr->bottom = l2;
            l2 = l2->bottom;
            curr = curr->bottom;
        }
    }

    if (l1)
        curr->bottom = l1;
    if (l2)
        curr->bottom = l2;

    return temp->bottom;
}
Node *flatten(Node *root)
{
    // Your code here
    if (!root || !root->next)
        return root;

    root->next = flatten(root->next);

    root = merge(root, root->next);

    return root;
}