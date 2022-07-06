bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    // Write your code here.
    if (!root1 && !root2)
        return true;
    else if (!root1 || !root2)
        return false;

    if (root1->data == root2->data)
    {
        return identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
    }
    return false;
}