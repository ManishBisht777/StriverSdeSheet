class Solution
{
private:
    int i = 0, k;
    void dfs(Node *root, int &a)
    {
        if (root == NULL)
            return;

        dfs(root->right, a);
        ++i;
        if (i == k)
            a = root->data;
        dfs(root->left, a);
    }

public:
    int kthLargest(Node *root, int K)
    {
        int a = -1;
        k = K;
        dfs(root, a);

        return a;
    }
};