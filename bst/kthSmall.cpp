void helper(TreeNode *root, int &ans, int &k)
{
    if (!root)
        return;

    helper(root->left, ans, k);

    if (--k == 0)
    {
        ans = root->val;
        return;
    }

    helper(root->right, ans, k);
}

int kthSmallest(TreeNode *root, int k)
{

    int ans = 0;
    helper(root, ans, k);
    return ans;
}