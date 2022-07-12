void helper(TreeNode<int> *root, int x, int &ans)
{
    if (!root)
        return;

    if (root->val > x)
        helper(root->left, x, ans);
    else if (root->val <= x)
    {
        ans = root->val;
        helper(root->right, x, ans);
    }
}

int floorInBST(TreeNode<int> *root, int x)
{
    // Write your code here.
    int ans = INT_MAX;
    helper(root, x, ans);
    return ans;
}