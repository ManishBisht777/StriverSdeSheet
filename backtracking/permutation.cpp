void helper(vector<vector<int>> &ans, vector<int> &nums, int pos)
{
    if (pos >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = pos; i < nums.size(); i++)
    {
        swap(nums[i], nums[pos]);
        helper(ans, nums, pos + 1);
        swap(nums[i], nums[pos]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{

    vector<vector<int>> ans;
    helper(ans, nums, 0);
    return ans;
}