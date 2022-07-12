int findCeil(BinaryTreeNode<int> *root, int key)
{

    int ans = -1;

    while (root)
    {
        if (root->data == key)
            return root->data;

        if (root->data < key)
            root = root->right;
        else
        {
            ans = root->data;
            root = root->left;
        }
    }
    return ans;
}