void helper(vector<vector<int>> &ans, vector<int> &nums, vector<int> &set, int i)
{
    ans.push_back(set);
    for (int j = i; j < nums.size(); j++)
    {
        if (j != i && nums[j] == nums[j - 1])
            continue;
        set.push_back(nums[j]);
        helper(ans, nums, set, j + 1);
        set.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int> set;
    helper(ans, nums, set, 0);

    return ans;
}