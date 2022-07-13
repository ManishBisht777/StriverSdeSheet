bool helper(TreeNode *root, int k, unordered_set<int> &set)
{
    if (!root)
        return false;

    if (set.count(k - root->val))
        return true;
    set.insert(root->val);
    return helper(root->left, k, set) || helper(root->right, k, set);
}

bool findTarget(TreeNode *root, int k)
{
    unordered_set<int> set;
    return helper(root, k, set);
}