void helper(vector<vector<int>> &ans, vector<int> &temp, vector<int> &candidates, int target, int curridx, int sum)
{

    if (sum == target)
    {
        ans.push_back(temp);
        return;
    }

    if (sum > target)
        return;

    for (int i = curridx; i < candidates.size(); i++)
    {
        temp.push_back(candidates[i]);
        sum += candidates[i];

        helper(ans, temp, candidates, target, i, sum);

        temp.pop_back();
        sum -= candidates[i];
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    vector<int> temp;
    vector<vector<int>> ans;

    helper(ans, temp, candidates, target, 0, 0);

    return ans;
}