
// brute force
int longestConsecutive(vector<int> &nums)
{

    sort(nums.begin(), nums.end());

    int curr = 1;
    int ans = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1] + 1)
            curr++;
        else if (nums[i] == nums[i - 1])
            continue;
        else
            ans = 1;

        ans = max(ans, curr);
    }

    return ans;
}

// optimal

int longestConsecutive(vector<int> &num)
{
    if (num.size() == 0)
        return 0;
    unordered_set<int> record(num.begin(), num.end());
    int res = 1;
    for (int n : num)
    {
        if (record.find(n) == record.end())
            continue;
        record.erase(n);
        int prev = n - 1, next = n + 1;
        while (record.find(prev) != record.end())
            record.erase(prev--);
        while (record.find(next) != record.end())
            record.erase(next++);
        res = max(res, next - prev - 1);
    }
    return res;
}