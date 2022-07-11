bool solve(TreeNode *root, long min, long max)
{
    if (!root)
        return true;

    if (root->val >= max || root->val <= min)
        return false;

    return solve(root->left, min, root->val) && solve(root->right, root->val, max);
}

bool isValidBST(TreeNode *root)
{

    return solve(root, LONG_MIN, LONG_MAX);
}