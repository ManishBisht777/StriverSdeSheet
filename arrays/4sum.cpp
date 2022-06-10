vector<vector<int>> fourSum(vector<int> &nums, int target)
{

    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    if (n < 4)
        return ans;

    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int x = target - nums[i] - nums[j];

            int st = j + 1;
            int end = n - 1;
            while (st < end)
            {

                int sum = nums[st] + nums[end];
                if (sum == x)
                {
                    ans.push_back({nums[i], nums[j], nums[st], nums[end]});
                    do
                    {
                        st++;
                    } while (nums[st] == nums[st - 1] && st < end);
                    do
                    {
                        end--;
                    } while (nums[end] == nums[end + 1] && st < end);
                }
                else if (sum > x)
                    end--;
                else
                    st++;
            }
        }
    }

    return ans;
}