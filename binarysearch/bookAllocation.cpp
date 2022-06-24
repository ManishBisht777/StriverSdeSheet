bool ispossible(vector<int> time, int n, long long mid)
{
    long long cnt = 1;
    long long temp = 0;
    for (long long i = 0; i < time.size(); i++)
    {
        if (temp + time[i] <= mid)
        {
            temp = temp + time[i];
        }
        else
        {
            cnt++;
            if (cnt > n || time[i] > mid)
                return false;
            temp = time[i];
        }
    }

    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    long long st = 0;
    long long end = 0;
    long long ans = -1;
    for (long long i = 0; i < m; i++)
        end += time[i];

    while (st <= end)
    {
        long long mid = st + (end - st) / 2;

        if (ispossible(time, n, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            st = mid + 1;
    }

    return ans;
}