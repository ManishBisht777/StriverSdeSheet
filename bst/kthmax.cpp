void helper(TreeNode<int> *root, int &k, int &ans)
{
    if (!root)
        return;

    helper(root->right, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    helper(root->left, k, ans);
}

int KthLargestNumber(TreeNode<int> *root, int k)
{
    // Write your code here.
    if (!root)
        return -1;
    int i = 0, ans = -1;
    helper(root, k, ans);
    return ans;
}