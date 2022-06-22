int count(vector<vector<int>> &arr, int n, int m, int digit)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0, e = m - 1, mid = s + (e - s) / 2, ans = -1;
        while (s <= e)
        {
            if (arr[i][mid] <= digit)
            {
                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
            mid = s + (e - s) / 2;
        }
        if (ans >= 0)
            c += ans + 1;
    }
    return c;
}
int kMin(vector<vector<int>> &arr, int n, int m, int k)
{
    int start = 0, end = 100007;
    int mid = start + (end - start) / 2;
    int ans = arr[n - 1][n - 1];
    while (start < end)
    {
        int digits = count(arr, n, m, mid);
        if (digits >= k)
        {
            ans = mid;
            end = mid;
        }
        else
            start = mid + 1;
        mid = start + (end - start) / 2;
    }
    return ans;
}
int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size(), k = ((n * m) / 2) + 1;
    return kMin(matrix, n, m, k);
}