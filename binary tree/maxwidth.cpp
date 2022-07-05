int widthOfBinaryTree(TreeNode *root)
{

    if (!root)
        return 0;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    int ans = 0;

    while (!q.empty())
    {
        int min = q.front().second;

        int n = q.size();
        int fir, last = 0;
        for (int i = 0; i < n; i++)
        {
            int curr = q.front().second - min;

            TreeNode *node = q.front().first;
            q.pop();

            if (i == 0)
                fir = curr;
            if (i == n - 1)
                last = curr;

            if (node->left)
                q.push({node->left, 2LL * curr});
            if (node->right)
                q.push({node->right, 2LL * curr + 1});
        }
        ans = max(ans, last - fir + 1);
    }

    return ans;
}