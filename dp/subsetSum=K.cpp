bool issum(vector<int> &arr, int idx, int k, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (idx == 0)
        return (arr[0] == k);

    if (dp[idx][k] != -1)
        return dp[idx][k];

    bool nottake = issum(arr, idx - 1, k, dp);
    bool take = false;
    if (k >= arr[idx])
        take = issum(arr, idx - 1, k - arr[idx], dp);

    return dp[idx][k] = take || nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return issum(arr, n - 1, k, dp);
}

// tabulation

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k + 1));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            bool take = false;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            bool nottake = dp[i - 1][j];

            dp[i][j] = take || nottake;
        }
    }

    return dp[n - 1][k];
}

// space optimization

bool subsetSumToK(int n, int k, vector<int> &arr)
{

    vector<bool> prev(k + 1, false), curr(k + 1, false);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            bool take = false;
            if (arr[i] <= j)
                take = prev[j - arr[i]];
            bool nottake = prev[j];

            curr[j] = take || nottake;
        }
        prev = curr;
    }

    return prev[k];
}