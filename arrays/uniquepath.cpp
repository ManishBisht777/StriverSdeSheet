
// recursion
int helper(int m, int n, int i, int j)
{
    if (i >= m || j >= n)
        return 0;

    if (i == m - 1 && j == n - 1)
        return 1;

    int ans = 0;

    ans += helper(m, n, i + 1, j);
    ans += helper(m, n, i, j + 1);

    return ans;
}

int uniquePaths(int m, int n)
{
    return helper(m, n, 0, 0);
}

// dp

int helper(int m, int n, int i, int j, vector<vector<int>> &dp)
{
    if (i >= m || j >= n)
        return 0;

    if (i == m - 1 && j == n - 1)
        return 1;

    if (dp[i][j])
        return dp[i][j];

    int ans = 0;

    ans += helper(m, n, i + 1, j, dp);
    ans += helper(m, n, i, j + 1, dp);

    dp[i][j] = ans;
    return dp[i][j];
}

int uniquePaths(int m, int n)
{

    vector<vector<int>> dp(m, vector<int>(n));

    return helper(m, n, 0, 0, dp);
}