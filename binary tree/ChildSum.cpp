void changeTree(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    int child = 0;

    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        else if (root->right)
        {
            root->right->data = root->data;
        }
    }

    changeTree(root->left);
    changeTree(root->right);

    child = 0;

    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;
    if (root->right || root->left)
        root->data = child;
}