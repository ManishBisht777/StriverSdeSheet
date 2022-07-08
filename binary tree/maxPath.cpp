long long int helper(TreeNode<int> *root, long long int &ans)
{
    if (!root)
        return 0;

    long long int l = helper(root->left, ans);
    long long int r = helper(root->right, ans);
    ans = max(ans, l + r + root->val);

    return max(l, r) + root->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return -1;
    if (!root->left || !root->right)
        return -1;
    long long int maxi = 0;
    helper(root, maxi);
    return maxi;
}