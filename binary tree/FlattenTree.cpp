// recursive sol

void flatten(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    flatten(root->left);
    flatten(root->right);
    if (root->left)
    {
        TreeNode *right = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right)
            root = root->right;
        root->right = right;
    }
}

// morris method

void flatten(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            TreeNode *pre = curr->left;
            while (pre->right)
            {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}