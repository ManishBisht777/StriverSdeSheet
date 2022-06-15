int removeDuplicates(vector<int> &nums)
{
    int ans = 1;
    int j = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[j])
        {
            j++;
            nums[j] = nums[i];
            ans++;
        }
    }

    return ans;
}